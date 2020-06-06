#include "dataReadThread.hh"

// SSM library
#include "ECUPort.hh"
#include "Exceptions.hh"

#include <functional>
#include <iostream>
#include <unistd.h>

dataReadThread::dataReadThread(std::string port, QObject* parent)
  : m_port(port), QThread(parent) {}

void dataReadThread::run()
{

  SSM::CoolantTemperature coolant_temp;
  SSM::ManifoldRelativePressure manifold_pressure;
  SSM::BatteryVoltage battery_voltage;
  SSM::EngineSpeed engine_speed;
  
  SSM::Observables observables { &coolant_temp, &manifold_pressure,
				 &battery_voltage, &engine_speed };

  auto callback = std::bind(&dataReadThread::provideDataWrapper, 
			    this, std::placeholders::_1, std::placeholders::_2);

  // Periodically try establish connection to ECU and read
  while (true)
    {
      try
	{
	  // This starts an infinite loop read (can be broken through callback
	  // return value > 0)
	  SSM::ECUPort ecu_port(m_port);
	  ecu_port.continuousRead(observables, callback);
	}

      // ECU went offline, wait and re-establish connection as soon as available
      catch (SSM::ReadTimeout)
	{
	  sleep(5);
	}

    }
}

int dataReadThread::provideDataWrapper(const SSM::Observables& observables,
				       const SSM::Values& data)
{
  emit provideData(data);
  return 0;
}

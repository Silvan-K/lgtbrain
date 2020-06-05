#include "dataReadThread.hh"
#include "ECUPort.hh"

#include <functional>
#include <iostream>

dataReadThread::dataReadThread(std::string port, QObject* parent)
  : m_port(port), QThread(parent) {}

void dataReadThread::run()
{

  SSM::CoolantTemperature coolant_temp;
  SSM::ManifoldRelativePressure manifold_pressure;
  SSM::BatteryVoltage battery_voltage;
  SSM::AirFuelLeanCorrection af_correction;
  
  SSM::Observables observables { &coolant_temp, &manifold_pressure,
				 &battery_voltage, &af_correction };

  auto callback = std::bind(&dataReadThread::provideDataWrapper, 
			    this, std::placeholders::_1, std::placeholders::_2);
  
  m_port.continuousRead(observables, callback);
}

int dataReadThread::provideDataWrapper(const SSM::Observables& observables,
				       const SSM::Values& data)
{
  emit provideData(data);
  return 0;
}

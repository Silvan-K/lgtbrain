#include "dataReadThread.hh"
#include "ECUPort.hh"

#include <functional>

dataReadThread::dataReadThread(std::string port, QObject* parent)
  : m_port(port), QThread(parent) {}

void dataReadThread::run()
{

  SSM::ExhaustGasTemperature exhaust_gas_temp;
  SSM::ManifoldRelativePressure manifold_pressure;
  
  SSM::Observables observables { &exhaust_gas_temp, &manifold_pressure };

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

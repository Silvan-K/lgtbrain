#include "dataReadThread.hh"
#include "ECUPort.hh"
#include <cmath>

dataReadThread::dataReadThread(std::string port, QObject* parent)
  : m_port(port), QThread(parent) {}

void dataReadThread::run()
{
  double w = 1.0;
  
  forever
    {
     usleep(10000);
     w += 0.01;
     emit provideData(std::vector<double>{10*sin(w), 10*cos(w)});
    }

}

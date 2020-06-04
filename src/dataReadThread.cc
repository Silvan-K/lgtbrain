#include "dataReadThread.hh"

#include <cmath>

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

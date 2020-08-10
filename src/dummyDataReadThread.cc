#include "dummyDataReadThread.hh"

#include <vector>
#include <cmath>

void dummyDataReadThread::run()
{
  double x(0.);
  while(true)
    {
      std::vector<double> data(m_n);
      data[0] = 14.0*(1.0+cos(x));
      data[1] = 80.0*(1.0+sin(x));
      data[2] = 12.0*(1.0+cos(x));
      
      data[3] = 10.0*(0.7+cos(x));
      data[4] = 0.01;
      data[5] = 0.05;

      data[6] = 7000.0*(1.0+cos(x));
      data[7] = 15.0*(0.8+cos(x));
      data[8] = 100*(1.0+cos(x));
      
      emit provideData(data);
      x += 0.001;
      usleep(2000);
    }
}

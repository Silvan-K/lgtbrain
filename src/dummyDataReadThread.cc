#include "dummyDataReadThread.hh"

#include <vector>
#include <cmath>

void dummyDataReadThread::run()
{
  double x(0.);
  while(true)
    {
      std::vector<double> data(m_n);
      data[0] = 90.0*(1.0+cos(x));
      data[1] = 14.0*(1.0+sin(x));
      data[2] = 3000.0*(1.0+cos(x));
      data[3] = 10.0*(0.7+cos(x));
      emit provideData(data);
      x += 0.001;
      usleep(200);
    }
}

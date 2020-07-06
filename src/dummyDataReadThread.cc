#include "dummyDataReadThread.hh"

#include <vector>
#include <cmath>

void dummyDataReadThread::run()
{
  double x(0.);
  while(true)
    {
      std::vector<double> data(m_n, 90.0*cos(x));
      emit provideData(data);
      x += 0.001;
      usleep(700);
    }
}

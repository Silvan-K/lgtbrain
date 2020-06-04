#include "mainWindow.hh"
#include "gaugeCluster.hh"
#include "dataReadThread.hh"

mainWindow::mainWindow() : p_gauges(new gaugeCluster(this)),
			   p_datareader(new dataReadThread(this))
{
  setCentralWidget(p_gauges);
  p_datareader->start();
  
  typedef std::vector<double> doublevec;
  qRegisterMetaType<doublevec>("std::vector<double>");
  
  connect(p_datareader, &dataReadThread::provideData,
	  p_gauges, &gaugeCluster::updateValues);
  }

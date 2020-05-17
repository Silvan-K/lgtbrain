#include <iostream>
#include <QApplication>
#include "dataReadThread.hh"

//////////////////////////
//////////////////////////

#include <QMainWindow>
#include "gaugeCluster.hh"

class mainWindow : public QMainWindow
{

public:

  mainWindow() : p_gauges(new gaugeCluster(this)),
		 p_datareader(new dataReadThread(this))
  {
    setCentralWidget(p_gauges);
    p_datareader->start();

    typedef std::vector<double> doublevec;
    qRegisterMetaType<doublevec>("std::vector<double>");

    connect(p_datareader, &dataReadThread::provideData,
	    p_gauges, &gaugeCluster::updateValues);
  };

private:

  gaugeCluster* p_gauges;
  dataReadThread* p_datareader;

};

//////////////////////////
//////////////////////////

int main(int argc, char *argv[]) {

  // QApplication specializes QGUIApplication, which specializes
  // QCoreApplication. Use QApplication for anything that uses
  // QWidgets and instantiate before any other QT objects.
  QApplication app(argc, argv);
  app.setApplicationName("LGTInfo");
  
  QMainWindow* mainWin = new mainWindow();
  mainWin->show();
  
  return app.exec();
}

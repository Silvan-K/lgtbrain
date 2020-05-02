#include <iostream>
#include <unistd.h>
#include <QApplication>

//////////////////////////
//////////////////////////

#include <QMainWindow>
#include "gaugeCluster.hh"

class mainWindow : public QMainWindow
{

public:

  mainWindow() : p_gauges(new gaugeCluster(this))
  {
    setCentralWidget(p_gauges);
  };

private:

  gaugeCluster* p_gauges;

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
  

  // for(int i=0; i<100; i++)
  //   {
  //     usleep(100000);
  //     gauges->updateValue(i);
  //     qApp->processEvents();
  //    }
  
  return app.exec();
}

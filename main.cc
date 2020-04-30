#include <iostream>
#include <unistd.h>

#include <QApplication>

#include "gaugeCluster.hh"

int main(int argc, char *argv[]) {

  // QApplication specializes QGUIApplication, which specializes
  // QCoreApplication. Use QApplication for anything that uses
  // QWidgets and instantiate before any other QT objects.
  QApplication app(argc, argv);
  
  gaugeCluster* gauges = new gaugeCluster();
  
  gauges->resize(350, 150);
  gauges->setWindowTitle("Cursors");
  gauges->show();
 
  for(int i=0; i<10000; i++)
    {
      usleep(100000);
      gauges->updateValue(i);
      qApp->processEvents();
     }
  
  return app.exec();
}

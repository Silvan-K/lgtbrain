#include <QApplication>
#include "mainWindow.hh"

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

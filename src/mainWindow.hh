#include <QMainWindow>

class gaugeCluster;
class dataReadThread;

class mainWindow : public QMainWindow
{

public:
  mainWindow();

private:
  gaugeCluster* p_gauges;
  dataReadThread* p_datareader;

};


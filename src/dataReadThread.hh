#ifndef __DATA_READ_THREAD_HH
#define __DATA_READ_THREAD_HH

#include <QThread>

class dataReadThread : public QThread {

  Q_OBJECT

public:

  dataReadThread(QObject* parent=0) : QThread(parent) {};

signals:

  void provideData(std::vector<double> data);

protected:

  void run() override;
  
};

#endif

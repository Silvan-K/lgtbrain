#ifndef __DATA_READ_THREAD_HH
#define __DATA_READ_THREAD_HH

#include "ECUPort.hh"

#include <QThread>

class dataReadThread : public QThread {

  Q_OBJECT

public:

  dataReadThread(std::string port, QObject* parent=0);

signals:

  void provideData(std::vector<double> data);

protected:

  void run() override;

private:

  SSM::ECUPort m_port;
  
};

#endif

#pragma once

#include <QThread>

class dummyDataReadThread : public QThread {

  Q_OBJECT

public:

  dummyDataReadThread(int num_data, QObject* parent=0)
    : m_n(num_data), QThread(parent) {};

signals:

  void provideData(std::vector<double> data);
  
protected:

  void run() override;

private:

  int m_n;

};


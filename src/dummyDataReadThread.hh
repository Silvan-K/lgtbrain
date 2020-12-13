#pragma once

#include <QThread>

class dummyDataReadThread : public QThread {

  Q_OBJECT

public:

  dummyDataReadThread(QObject* parent=0)
    : QThread(parent) {};

signals:

  void provideData(std::vector<double> data);
  
protected:

  void run() override;

};


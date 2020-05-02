#ifndef __GAUGE_HH
#define __GAUGE_HH

#include <QFrame>

class QLCDNumber;
class QLabel;

class gauge : public QFrame {

  Q_OBJECT

public:

  gauge( QWidget* parent =0);
  
  void updateValue(double val);

private:

  QLCDNumber* p_num;
  QLabel* p_label;
  
};

#endif

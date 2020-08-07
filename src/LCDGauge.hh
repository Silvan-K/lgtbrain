#ifndef __LCD_GAUGE_HH
#define __LCD_GAUGE_HH

#include <QFrame>

class QLCDNumber;
class QLabel;

class LCDGauge : public QFrame {

  Q_OBJECT

public:

  LCDGauge(const std::string& label,
	   int num_dig,
	   QWidget* parent=0);
  void updateValue(double val);

private:

  QLCDNumber* p_num;
  QLabel* p_label;
  
};

#endif

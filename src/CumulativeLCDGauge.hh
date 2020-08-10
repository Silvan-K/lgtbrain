#ifndef __CUMULATIVE_LCD_GAUGE_HH
#define __CUMULATIVE_LCD_GAUGE_HH

#include "LCDGauge.hh"

class CumulativeLCDGauge : public LCDGauge {

  Q_OBJECT

public:

  CumulativeLCDGauge(const std::string& label,
	   int num_dig,
	   QWidget* parent=0);
  void updateValue(double val) override;

private:
  
  double m_cur;
  
};

#endif

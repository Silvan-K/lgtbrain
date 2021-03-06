#ifndef __BAR_GAUGE_HH
#define __BAR_GAUGE_HH

#include <QFrame>
#include <string>

class bar;
class QLabel;

class barGauge : public QFrame
{
      Q_OBJECT

public:

  explicit barGauge(const std::string& label,
		    double min,double max,
		    QWidget *parent = nullptr);

  void updateValue(double value);

private:

  QLabel* p_label;
  bar*    p_bar;
};

#endif

#ifndef __BAR_HH
#define __BAR_HH

#include <QFrame>
#include <QFont>

class bar : public QFrame
{
      Q_OBJECT

public:

  explicit bar(double min,
	       double max,
	       double val,
	       QWidget *parent = nullptr);
  
  void updateValue(double value);
  
  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;

protected:
  
  void paintEvent(QPaintEvent *event) override;

private:

  double m_val;
  double m_min;
  double m_max;
  static constexpr double m_bar_height = 400.;
  static constexpr double m_bar_width  = 40.;

  QFont m_font;
};

#endif

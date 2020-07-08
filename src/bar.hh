#ifndef __BAR_HH
#define __BAR_HH

#include <QFrame>
#include <QRect>

class bar : public QFrame
{
      Q_OBJECT

public:

  explicit bar(double frac, QWidget *parent = nullptr);
  void updateFraction(double frac);
  
  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;

protected:
  
  void paintEvent(QPaintEvent *event) override;

private:

  double m_frac;
  QRect m_rect;
  static constexpr double  m_height = 200.;
  static constexpr double  m_width = 20.;
};

#endif

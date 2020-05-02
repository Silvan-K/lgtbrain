#ifndef __GAUGE_HH
#define __GAUGE_HH

#include <QFrame>
#include <QGridLayout>

class QLCDNumber;
#include <QSizePolicy>

class QLayout;
class QWidget;

class gauge : public QWidget {

  Q_OBJECT

public:

  gauge( QWidget* parent =0);
  void updateValue(double val);

  QSize sizeHint() const override
  {
    return QSize(m_width, m_height);
  };

private:

  static constexpr double m_width = 170;
  static constexpr double m_height = 200;

  QLayout* p_layout;
  QLCDNumber* p_num;

};

#endif

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

public:

  void updateValue(double val);


private:

  QLayout* p_layout;
  QLCDNumber* p_num;

};

#endif

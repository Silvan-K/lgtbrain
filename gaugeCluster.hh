#ifndef __GAUGE_CLUSTER_HH
#define __GAUGE_CLUSTER_HH

#include <QFrame>

class QGridLayout;
class gauge;

class gaugeCluster : public QFrame {

  Q_OBJECT

public:

  gaugeCluster(QWidget* parent =0 );

public:

  void updateValue(double val);

  QSize sizeHint() const override;

private:

  QGridLayout* p_layout;
  gauge* p_gauge;
  gauge* p_gauge_;

};

#endif

#ifndef __GAUGE_CLUSTER_HH
#define __GAUGE_CLUSTER_HH

#include <QWidget>

class QLayout;
class gauge;

class gaugeCluster : public QWidget {

  Q_OBJECT

public:

  gaugeCluster(QWidget* parent =0 );

public:

  void updateValue(double val);

private:

  QLayout* p_layout;
  gauge* p_gauge;

};

#endif

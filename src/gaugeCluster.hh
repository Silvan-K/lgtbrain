#ifndef __GAUGE_CLUSTER_HH
#define __GAUGE_CLUSTER_HH

#include <QFrame>

class gauge;
class barGauge;

class gaugeCluster : public QFrame {

  Q_OBJECT

public:

  gaugeCluster(QWidget* parent =0 );

public:

  void updateValues(std::vector<double> values);

private:

  std::vector<gauge*> p_gauges;
  barGauge* p_bar_gauge;
};

#endif

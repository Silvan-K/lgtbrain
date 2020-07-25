#ifndef __GAUGE_CLUSTER_HH
#define __GAUGE_CLUSTER_HH

#include <QFrame>

class LCDGauge;
class barGauge;

class gaugeCluster : public QFrame {

  Q_OBJECT

public:

  gaugeCluster(QWidget* parent = 0);

public:

  void updateValues(std::vector<double> values);

private:

  std::vector<LCDGauge*> p_gauges;
  barGauge* p_rpm_gauge;
  barGauge* p_boost_gauge;
};

#endif

#include "gaugeCluster.hh"
#include "CumulativeLCDGauge.hh"
#include "LCDGauge.hh"
#include "barGauge.hh"

#include <QGridLayout>
#include <QPalette>
#include <QWidget>

gaugeCluster::gaugeCluster(QWidget* parent) : QFrame(parent)
{
  p_gauges.resize(6);
  p_gauges[0] = new LCDGauge("Battery [V]", 2, this);
  p_gauges[1] = new LCDGauge("Coolant [C]", 2, this);
  p_gauges[2] = new LCDGauge("Learned [deg]", 4, this);
  
  p_gauges[3] = new LCDGauge("Knock Corr [deg]", 4, this);
  p_gauges[4] = new CumulativeLCDGauge("Knock 1 [#]", 2, this);
  p_gauges[5] = new CumulativeLCDGauge("Knock 2 [#]", 2, this);
  
  p_rpm_gauge   = new barGauge("Engine [RPM]", 0, 7000, this);
  p_boost_gauge = new barGauge("Boost [psi]", -12, 15, this);
  p_throttle_gauge = new barGauge("Throttle [%]", 0, 100, this);

  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_gauges[0],   0, 0, 1, 1);
  layout->addWidget(p_gauges[1],   1, 0, 1, 1);
  layout->addWidget(p_gauges[2],   2, 0, 1, 1);
  
  layout->addWidget(p_gauges[3],   0, 1, 1, 1);
  layout->addWidget(p_gauges[4],   1, 1, 1, 1);
  layout->addWidget(p_gauges[5],   2, 1, 1, 1);
  
  layout->addWidget(p_rpm_gauge,   0, 2, 3, 1);
  layout->addWidget(p_boost_gauge, 0, 3, 3, 1);
  layout->addWidget(p_throttle_gauge, 0, 4, 3, 1);
  setLayout(layout);

  setBackground();
}

void gaugeCluster::resizeEvent(QResizeEvent* event)
{
  QWidget::resizeEvent(event);
  setBackground();
}

void gaugeCluster::updateValues(std::vector<double> values)
{
  p_gauges[0]->updateValue(values[0]);
  p_gauges[1]->updateValue(values[1]);
  p_gauges[2]->updateValue(values[2]);

  p_gauges[3]->updateValue(values[3]);
  p_gauges[4]->updateValue(values[4]);
  p_gauges[5]->updateValue(values[5]);
  
  p_rpm_gauge->updateValue(values[6]);
  p_boost_gauge->updateValue(values[7]);
  p_throttle_gauge->updateValue(values[8]);
}

void gaugeCluster::setBackground()
{
  QLinearGradient gradient(0,0,0,height());
  gradient.setColorAt(1.0, "#d7d2cc");
  gradient.setColorAt(0.0, "#304352");
  QPalette pal = palette();
  pal.setBrush(QPalette::Window, gradient);
  setAutoFillBackground(true);
  setPalette(pal);
}

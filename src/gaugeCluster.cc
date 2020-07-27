#include "gaugeCluster.hh"
#include "LCDGauge.hh"
#include "barGauge.hh"

#include <QGridLayout>
#include <QPalette>
#include <QWidget>

gaugeCluster::gaugeCluster(QWidget* parent) : QFrame(parent)
{
  p_gauges.resize(2);
  p_gauges[0] = new LCDGauge("Coolant [C]", this);
  p_gauges[1] = new LCDGauge("Battery [V]", this);
  p_rpm_gauge   = new barGauge("Engine [RPM]", 0, 7000, this);
  p_boost_gauge = new barGauge("Boost [psi]", -12, 15, this);

  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_gauges[0],   0, 0, 1, 1);
  layout->addWidget(p_gauges[1],   1, 0, 1, 1);
  layout->addWidget(p_rpm_gauge,   0, 1, 2, 1);
  layout->addWidget(p_boost_gauge, 0, 2, 2, 1);
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
  p_rpm_gauge->updateValue(values[2]);
  p_boost_gauge->updateValue(values[3]);
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

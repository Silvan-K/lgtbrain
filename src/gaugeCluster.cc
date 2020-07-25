#include "LCDGauge.hh"
#include "gaugeCluster.hh"
#include "barGauge.hh"

#include <QGridLayout>
#include <QPalette>
#include <QWidget>

gaugeCluster::gaugeCluster(QWidget* parent) : QFrame(parent)
{
  p_gauges.resize(2);
  p_gauges[0] = new LCDGauge("Coolant [C]", this);
  p_gauges[1] = new LCDGauge("Battery [V]", this);
  p_rpm_gauge   = new barGauge("Engine [RPM]", 0, 8000, this);
  p_boost_gauge = new barGauge("Boost [psi]", -11, 30, this);

  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_gauges[0],   0, 0, 1, 1);
  layout->addWidget(p_gauges[1],   1, 0, 1, 1);
  layout->addWidget(p_rpm_gauge,   0, 1, 2, 1);
  layout->addWidget(p_boost_gauge, 0, 2, 2, 1);
  setLayout(layout);

  QGradient gradient(QGradient::CochitiLake);
  QPalette pal = palette();
  pal.setBrush(QPalette::Window, gradient);
  setAutoFillBackground(true);
  setPalette(pal);
}

void gaugeCluster::updateValues(std::vector<double> values)
{
  p_gauges[0]->updateValue(values[0]);
  p_gauges[1]->updateValue(values[1]);
  p_rpm_gauge->updateValue(values[2]);
  p_boost_gauge->updateValue(values[3]);
}

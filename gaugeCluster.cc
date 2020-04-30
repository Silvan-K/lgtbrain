#include "gauge.hh"
#include "gaugeCluster.hh"
#include <QGridLayout>

#include <QWidget>

gaugeCluster::gaugeCluster([[maybe_unused]] QWidget* parent)
{
  p_gauge = new gauge(this);
  QGridLayout *p_layout = new QGridLayout(this);
  
  p_layout->addWidget(p_gauge, 0, 0);
  setLayout(p_layout);
}

void gaugeCluster::updateValue(double val)
{
  p_gauge->updateValue(val);
}

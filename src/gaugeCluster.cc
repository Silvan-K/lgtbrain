#include "gauge.hh"
#include "gaugeCluster.hh"

#include <QGridLayout>
#include <QWidget>

gaugeCluster::gaugeCluster(QWidget* parent) : QFrame(parent)
{
  p_gauges.resize(4);
  p_gauges[0] = new gauge("Coolant [C]", this);
  p_gauges[1] = new gauge("Boost [psi]", this);
  p_gauges[2] = new gauge("Battery [V]", this);
  p_gauges[3] = new gauge("Engine [kRPM]", this);
  
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_gauges[0], 0, 0);
  layout->addWidget(p_gauges[1], 0, 1);
  layout->addWidget(p_gauges[2], 1, 0);
  layout->addWidget(p_gauges[3], 1, 1);
  setLayout(layout);

  //setFrameStyle(QFrame::Panel | QFrame::Raised); setLineWidth(2);
}

void gaugeCluster::updateValues(std::vector<double> values)
{
  p_gauges[0]->updateValue(values[0]);
  p_gauges[1]->updateValue(values[1]);
  p_gauges[2]->updateValue(values[2]);
  p_gauges[3]->updateValue(values[3]/1000.0);
}

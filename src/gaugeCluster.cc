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
  p_gauges[3] = new gauge("AF Corr [%]", this);
  
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_gauges[0], 0, 0);
  layout->addWidget(p_gauges[1], 0, 1);
  layout->addWidget(p_gauges[2], 1, 0);
  layout->addWidget(p_gauges[3], 1, 1);
  setLayout(layout);

  //setFrameStyle(QFrame::Panel | QFrame::Raised);
  //setLineWidth(2);
  updateValues({10.,20.});

  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void gaugeCluster::updateValues(std::vector<double> values)
{
  auto v = values.begin();
  auto g = p_gauges.begin();
  for(; (v!=values.end() && g!=p_gauges.end()) ; ++v , ++g)
      (*g)->updateValue(*v);
}

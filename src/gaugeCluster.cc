#include "gauge.hh"
#include "gaugeCluster.hh"

#include <QGridLayout>
#include <QWidget>

gaugeCluster::gaugeCluster(QWidget* parent) : QFrame(parent)
{
  p_gauges.resize(2);
  p_gauges[0] = new gauge("TMP", this);
  p_gauges[1] = new gauge("MTP", this);
  
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_gauges[0], 0, 0);
  layout->addWidget(p_gauges[1], 1, 1);
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

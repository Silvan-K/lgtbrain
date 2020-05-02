#include "gauge.hh"
#include "gaugeCluster.hh"

#include <QGridLayout>
#include <QWidget>

gaugeCluster::gaugeCluster(QWidget* parent) : QFrame(parent)
{
  p_gauge  = new gauge(this);
  p_gauge_ = new gauge(this);
  
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_gauge,  0, 0);
  layout->addWidget(p_gauge_, 0, 1);
  setLayout(layout);

  //setFrameStyle(QFrame::Panel | QFrame::Raised);
  //setLineWidth(2);
  updateValue(10);

  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void gaugeCluster::updateValue(double val)
{
  p_gauge->updateValue(val);
  p_gauge_->updateValue(21);
}

#include "gauge.hh"
#include "gaugeCluster.hh"

#include <QGridLayout>
#include <QWidget>

QSize gaugeCluster::sizeHint() const
{
  return p_layout->sizeHint();
}

gaugeCluster::gaugeCluster(QWidget* parent) : QFrame(parent)
{
  p_layout = new QGridLayout(this);
  
  p_gauge  = new gauge(this);
  p_gauge_ = new gauge(this);
  p_layout->addWidget(p_gauge, 0, 0);
  p_layout->addWidget(p_gauge_, 0, 1);
  setLayout(p_layout);

  setFrameStyle(QFrame::Panel | QFrame::Raised);
  setLineWidth(2);
  updateValue(10);

  setMinimumSize(500,500);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void gaugeCluster::updateValue(double val)
{
  p_gauge->updateValue(val);
  p_gauge_->updateValue(21);
}

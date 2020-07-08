#include "barGauge.hh"
#include "bar.hh"

#include <QLayout>
#include <QLabel>

barGauge::barGauge(const std::string& label,
		   double min, double max,
		   QWidget *parent) :
  QFrame(parent),
  p_bar(nullptr),
  m_min(min),
  m_max(max)
  
{
  // Set up the label displaying the unit
  p_label = new QLabel(label.c_str(), this);
  p_label->setFont(QFont("DejaVu Sans", 14));
  p_label->setAlignment(Qt::AlignRight | Qt::AlignBottom);

  // Set up the bar that visualizes the value
  p_bar = new bar(1.0, this);

  // Arrange items in layout
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_bar, 0, 0, Qt::AlignCenter | Qt::AlignBottom);
  layout->addWidget(p_label, 1, 0, Qt::AlignCenter);
  setLayout(layout);
}

void barGauge::updateValue(double value)
{
  double fraction = (value-m_min)/(m_max-m_min);
  p_bar->updateFraction(fraction);
  QWidget::update();
}

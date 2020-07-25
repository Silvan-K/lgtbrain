#include "barGauge.hh"
#include "bar.hh"

#include <QLayout>
#include <QLabel>

barGauge::barGauge(const std::string& label,
		   double min, double max,
		   QWidget *parent) :
  QFrame(parent),
  p_bar(nullptr)
{
  // Set up the label displaying the unit
  p_label = new QLabel(label.c_str(), this);
  p_label->setFont(QFont("DejaVu Sans", 16, QFont::Bold));
  p_label->setAlignment(Qt::AlignCenter);

  // Set up the bar that visualizes the value
  p_bar = new bar(min, max, min, this);

  // Arrange items in layout : ROW, COLUMN, ROWSPAN, COLUMNSPAN
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_bar,  0, 0, 1, 1, Qt::AlignCenter);
  layout->addWidget(p_label,1, 0, 1, 1, Qt::AlignCenter);
  setLayout(layout);
}

void barGauge::updateValue(double value)
{
  p_bar->updateValue(value);
  QWidget::update();
}

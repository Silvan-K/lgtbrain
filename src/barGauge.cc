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
  p_label->setFont(QFont("DejaVu Sans", 16, QFont::Bold));
  p_label->setAlignment(Qt::AlignRight | Qt::AlignBottom);

  // Set up the bar that visualizes the value
  p_bar = new bar(-100, +100, 50, this);

  // Arrange items in layout : ROW, COLUMN, ROWSPAN, COLUMNSPAN
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_bar,  0, 0, 1, 1, Qt::AlignCenter | Qt::AlignBottom);
  layout->addWidget(p_label,1, 0, 1, 1, Qt::AlignRight  | Qt::AlignTop);
  
  // layout->setVerticalSpacing(0);
  // layout->setHorizontalSpacing(0);
  // layout->setColumnStretch(0,0);
  // layout->setColumnStretch(1,0);
  // layout->setColumnMinimumWidth(0,0);
  // layout->setColumnMinimumWidth(1,0);
  // layout->setRowStretch(0,0);
  // layout->setRowStretch(1,0);
  // layout->setRowStretch(2,0);

  // p_bar->setFrameStyle(QFrame::Box);
  // p_bar->setLineWidth(2);
  
  setLayout(layout);
}

void barGauge::updateValue(double value)
{
  p_bar->updateValue(value);
  QWidget::update();
}

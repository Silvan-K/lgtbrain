#include "LCDGauge.hh"

#include <QLCDNumber>
#include <QLabel>
#include <QSizePolicy>
#include <QGridLayout>

LCDGauge::LCDGauge(const std::string& label,
		   int num_dig,
		   QWidget* parent) : QFrame(parent)
{
  //setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  // Set up the LCD number object displaying the value
  p_num = new QLCDNumber(this);
  p_num->setFixedSize(100, 75);
  p_num->setFrameStyle(0);
  p_num->setDigitCount(num_dig);

  // Set up the label displaying the unit
  p_label = new QLabel(label.c_str(), this);
  p_label->setFont(QFont("DejaVu Sans", 14, QFont::Bold));

  // Arrange both in layout
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_num,   0, 0, Qt::AlignCenter);
  layout->addWidget(p_label, 1, 0, Qt::AlignCenter);
  setLayout(layout);
}

void LCDGauge::updateValue(double val)
{
  p_num->display(val);
}

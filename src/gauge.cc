#include "gauge.hh"

#include <QLCDNumber>
#include <QLabel>
#include <QSizePolicy>
#include <QGridLayout>

gauge::gauge(const std::string& label, QWidget* parent) : QFrame(parent)
{
  // Set up the LCD number object displaying the value
  p_num = new QLCDNumber(this);
  p_num->setFixedSize(160, 150);
  p_num->setFrameStyle(0);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  p_num->setDigitCount(3);

  // Set up the label displaying the unit
  p_label = new QLabel(label.c_str(), this);
  p_label->setFont(QFont("DejaVu Sans", 14));
  p_label->setAlignment(Qt::AlignRight | Qt::AlignBottom);

  // Arrange both in layout
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_num,   0, 0);
  layout->addWidget(p_label, 1, 0);
  setLayout(layout);
}

void gauge::updateValue(double val)
{
  p_num->display(val);
}

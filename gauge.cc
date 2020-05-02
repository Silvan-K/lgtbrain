#include "gauge.hh"

#include <QLCDNumber>
#include <QLabel>
#include <QSizePolicy>
#include <QGridLayout>

gauge::gauge(const std::string& label, QWidget* parent) : QFrame(parent)
{
  // Set up the LCD number object displaying the value
  p_num = new QLCDNumber(this);
  p_num->setFixedSize(150, 150);
  p_num->setFrameStyle(QFrame::Box);
  setSizePolicy(QSizePolicy::Fixed,
   		QSizePolicy::Fixed);
  p_num->setDigitCount(2);

  // Set up the label displaying the unit
  p_label = new QLabel("Obs / [U]", this);
  p_label->setFont(QFont("DejaVu Sans", 20));
  p_label->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
  p_label->setFrameStyle(QFrame::Box);

  // Arrange both in layout
  QGridLayout* layout = new QGridLayout(this);
  layout->addWidget(p_num,   0, 1);
  layout->addWidget(p_label, 0, 0);
  setLayout(layout);

  // A box while we debug the layouts
  setFrameStyle(QFrame::Box);
}

void gauge::updateValue(double val)
{
  p_num->display(val);
}

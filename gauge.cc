#include "gauge.hh"

#include <QLCDNumber>

gauge::gauge([[maybe_unused]] QWidget* parent)
{
  p_num = new QLCDNumber(this);
  p_num->setFixedSize(200,200);
}

void gauge::updateValue(double val)
{
  p_num->display(val);
}

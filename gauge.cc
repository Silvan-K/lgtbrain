#include "gauge.hh"

#include <QLCDNumber>
#include <QSizePolicy>

gauge::gauge(QWidget* parent) : QWidget(parent)
{
  p_num = new QLCDNumber(this);
  p_num->setFixedSize(m_width, m_height);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void gauge::updateValue(double val)
{
  p_num->display(val);
}

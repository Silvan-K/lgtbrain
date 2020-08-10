#include "CumulativeLCDGauge.hh"
#include <QLCDNumber>

CumulativeLCDGauge::
CumulativeLCDGauge(const std::string& label,
		   int num_dig,
		   QWidget* parent) : LCDGauge(label, num_dig, parent)
{}

void CumulativeLCDGauge::updateValue(double val)
{
  m_cur += val;
  p_num->display(m_cur);
}

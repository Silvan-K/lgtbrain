#include "bar.hh"

#include <QPainter>
#include <QRectF>
#include <QString>
#include <QPen>

bar::bar(double min, double max, double val, QWidget *parent) :
  QFrame(parent), m_min(min), m_max(max), m_val(val),
  m_font("DejaVu Sans", 16, QFont::Bold)
{
  m_label_hi = QString::number(m_max, 'f', 0);
  m_label_lo = QString::number(m_min, 'f', 0);

  // If vals have different sign, add explicit "+"
  m_label_hi = m_min*m_max<0 ? (QString("+")+m_label_hi) : m_label_hi;

  QFontMetrics fmetrics(m_font);
  m_label_box_hi = fmetrics.boundingRect(m_label_hi);
  m_label_box_lo = fmetrics.boundingRect(m_label_lo);

  m_width = m_bar_width +
	    m_bar_label_sep +
	    qMax(m_label_box_hi.width(), m_label_box_lo.width());

  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

QSize bar::sizeHint() const
{
  return QSize(m_width, m_bar_height);
}

QSize bar::minimumSizeHint() const
{
  return QSize(m_width, m_bar_height);
}

void bar::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  painter.setFont(m_font);

  // Make divisible by two to get symmetric full bar
  const int pen_width(2);
  const int border(pen_width/2);
  
  const double frac = (m_val-m_min)/(m_max-m_min);
  const QRect full(border, border, m_bar_width-border, m_bar_height-border);
  const QRect part(0, (1.0-frac)*m_bar_height, m_bar_width, m_bar_height*frac);

  // If vals have different sign, add explicit "+"
  QString label_cu(QString::number(m_val, 'f', 0));
  label_cu = m_min*m_val<0 ? (QString("+")+label_cu) : label_cu;

  QFontMetrics fmetrics(m_font);
  QRectF box_cu = fmetrics.boundingRect(label_cu);
  
  m_label_box_hi.moveTo(m_bar_width+m_bar_label_sep, 0);
  m_label_box_lo.moveTo(m_bar_width+m_bar_label_sep, m_bar_height-m_label_box_lo.height());
  box_cu.moveTo(m_bar_width+5, (1.0-frac)*m_bar_height-box_cu.height()/2);

  // Make sure the min/max labels don't overlap with the current value
  // label. Avoid overlap by restricting current label to be between
  // min and max labels.
  if(box_cu.intersects(m_label_box_lo))
    box_cu.moveTo(m_bar_width+5, m_label_box_lo.top()-box_cu.height());
  if(box_cu.intersects(m_label_box_hi))
    box_cu.moveTo(m_bar_width+5, m_label_box_hi.bottom());

  // Draw min/max/current value labels next to bar
  painter.drawText(m_label_box_hi, m_label_hi);
  painter.drawText(m_label_box_lo, m_label_lo);
  painter.drawText(box_cu, label_cu);

  // Draw partial bar
  QLinearGradient gradient(full.bottomLeft(), full.topLeft());
  gradient.setColorAt(0.00, "#2a5298");
  gradient.setColorAt(0.29, "#44107A");
  gradient.setColorAt(0.67, "#FF1361");
  gradient.setColorAt(1.00, "#FFF800");
  painter.setBrush(gradient);
  painter.setPen(Qt::NoPen);
  painter.drawRect(part);

  // Draw box around the space that the partial bar occupies at full
  // extent
  QPen pen;
  pen.setWidth(pen_width);
  painter.setPen(pen);
  painter.setBrush(Qt::NoBrush);
  painter.drawRect(full);
  
  QFrame::paintEvent(event);
}

void bar::updateValue(double val)
{
  // QWidget::update triggers re-draw via paintEvent
  m_val = val;
  QWidget::update();
}

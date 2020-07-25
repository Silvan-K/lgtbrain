#include "bar.hh"

#include <QPainter>
#include <QRectF>
#include <QString>
#include <QPen>

bar::bar(double min, double max, double val, QWidget *parent) :
  QFrame(parent), m_min(min), m_max(max), m_val(val),
  m_font("DejaVu Sans", 20, QFont::Bold) { }

QSize bar::sizeHint() const
{
  return QSize(m_bar_width+100, m_bar_height);
}

QSize bar::minimumSizeHint() const
{
  return QSize(m_bar_width+100, m_bar_height);
}

void bar::paintEvent(QPaintEvent *event)
{
  // Make divisible by two to get symmetric full bar
  const int pen_width(2);
  const int border(pen_width/2);
  
  const double frac = (m_val-m_min)/(m_max-m_min);
  const QRect full(border, border, m_bar_width-border, m_bar_height-border);
  const QRect part(0, (1.0-frac)*m_bar_height, m_bar_width, m_bar_height*frac);

  QPainter painter(this);
  painter.setFont(m_font);

  QString label_hi(QString::number(m_max, 'f', 0));
  QString label_lo(QString::number(m_min, 'f', 0));
  QString label_cu(QString::number(m_val, 'f', 0));

  // If vals have different sign, add explicit "+"
  label_hi = m_min*m_max<0 ? (QString("+")+label_hi) : label_hi;
  label_cu = m_min*m_val<0 ? (QString("+")+label_cu) : label_cu;

  QFontMetrics fmetrics(m_font);
  QRectF box_hi = fmetrics.boundingRect(label_hi);
  QRectF box_lo = fmetrics.boundingRect(label_lo);
  QRectF box_cu = fmetrics.boundingRect(label_cu);
  
  box_hi.moveTo(m_bar_width+5, 0);
  box_lo.moveTo(m_bar_width+5, m_bar_height-box_lo.height());
  box_cu.moveTo(m_bar_width+5, (1.0-frac)*m_bar_height-box_cu.height()/2);

  // Make sure the min/max labels don't overlap with the current value
  // label. Avoid overlap by restricting current label to be between
  // min and max labels.
  if(box_cu.intersects(box_lo))
    box_cu.moveTo(m_bar_width+5, box_lo.top()-box_cu.height());
  if(box_cu.intersects(box_hi))
    box_cu.moveTo(m_bar_width+5, box_hi.bottom());

  // Draw min/max/current value labels next to bar
  painter.drawText(box_hi, label_hi);
  painter.drawText(box_lo, label_lo);
  painter.drawText(box_cu, label_cu);

  // Draw partial bar
  QLinearGradient gradient(part.bottomLeft(), part.topLeft());
  gradient.setColorAt(0.0, Qt::blue);
  gradient.setColorAt(1.0, Qt::red);
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

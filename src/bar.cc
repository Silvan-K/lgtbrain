#include "bar.hh"

#include <QPainter>
#include <QPen>

bar::bar(double frac, QWidget *parent) :
  QFrame(parent), m_frac(frac) { }

QSize bar::sizeHint() const
{
  return QSize(m_width, m_height);
}

QSize bar::minimumSizeHint() const
{
  return QSize(m_width, m_height);
}

void bar::paintEvent(QPaintEvent *event)
{
  QRect full(0, 0, m_width, m_height);
  QRect part(0, (1.0-m_frac)*m_height,
	     m_width, m_height*m_frac);

  // Draw partial bar
  QPainter painter(this);
  QLinearGradient gradient(full.bottomLeft(), full.topLeft());
  gradient.setColorAt(0.0, Qt::blue);
  gradient.setColorAt(1.0, Qt::red);
  painter.setBrush(gradient);
  painter.setPen(Qt::NoPen);
  painter.drawRect(part);

  // Draw box around the space that the partial bar occupies at full
  // extent
  QPainter painter_full(this);
  painter_full.drawRect(full);

  QFrame::paintEvent(event);
}

void bar::updateFraction(double frac)
{
  // QWidget::update triggers re-draw via paintEvent
  m_frac = frac;
  QWidget::update();
}

#include "fontfallbackwidget.h"
#include <QPainter>
#include <QFont>
#include <QFontDatabase>

void FontFallbackWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QFont font("Noto Sans", 16); // Primary font: Noto Sans (Latin support)
    font.setFeature("ss03", 1);   // Enable stylistic set 03
    painter.setFont(font);

    // Text with Latin and CJK characters
    QString text = "Hello 世界"; // "Hello" (Latin) + "World" in Chinese
    painter.drawText(50, 50, text);
}

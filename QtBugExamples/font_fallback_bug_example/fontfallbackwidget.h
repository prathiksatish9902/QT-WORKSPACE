#ifndef FONTFALLBACKWIDGET_H
#define FONTFALLBACKWIDGET_H

#pragma once

#include <QWidget>

class FontFallbackWidget : public QWidget {
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *) override;
};
#endif // FONTFALLBACKWIDGET_H

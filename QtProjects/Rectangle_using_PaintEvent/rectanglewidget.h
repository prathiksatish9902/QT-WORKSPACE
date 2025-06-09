#ifndef RECTANGLEWIDGET_H
#define RECTANGLEWIDGET_H

#include <QWidget>

class RectangleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RectangleWidget(QWidget *parent = nullptr);

    void setRectangle(int x, int y, int width, int height);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QRect rectangleToDraw;
};

#endif // RECTANGLEWIDGET_H

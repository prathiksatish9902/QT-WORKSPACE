#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QPainterPath>

class DrawArea : public QWidget {
    Q_OBJECT

public:
    enum class ShapeType {
        None,
        Circle,
        Rectangle,
        Square,
        Pentagon,
        Line,
        CurvedLine
    };

    explicit DrawArea(QWidget *parent = nullptr);

    void setShape(ShapeType shape);
    void setPenWidth(int width);
    void setPenColor(const QColor &color);
    void setBrushColor(const QColor &color);

    ShapeType currentShapeType() const { return currentShape; }

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ShapeType currentShape;
    int penWidth;
    QColor penColor;
    QColor brushColor;
};

#endif // DRAWAREA_H

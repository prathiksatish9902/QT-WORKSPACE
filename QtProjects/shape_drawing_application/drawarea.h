#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QPainterPath>

class DrawArea : public QWidget {
    Q_OBJECT

public:
    enum ShapeType {
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

    ShapeType currentShapeType() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ShapeType m_currentShape;
    int m_penWidth;
    QColor m_penColor;
    QColor m_brushColor;
};

#endif // DRAWAREA_H

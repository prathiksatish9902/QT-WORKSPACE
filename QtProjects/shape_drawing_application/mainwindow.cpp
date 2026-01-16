#include "mainwindow.h"
#include "drawarea.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    m_shapeTypes{DrawArea::Circle, DrawArea::Rectangle, DrawArea::Square, DrawArea::Pentagon, DrawArea::Line, DrawArea::CurvedLine},
    m_shapeNames{"Circle", "Rectangle", "Square", "Pentagon", "Line", "CurvedLine"}
{
    m_drawArea = new DrawArea(this);
    m_penWidthEdit = new QLineEdit("2", this);
    m_penColorEdit = new QLineEdit("black", this);
    m_brushColorEdit = new QLineEdit("white", this);

    m_mainLayout = new QHBoxLayout(this);

    m_shapeButtonsLayout = new QVBoxLayout();
    for (int i = 0; i < m_shapeTypes.size(); ++i) {
        QPushButton *button = new QPushButton(m_shapeNames[i], this);
        m_shapeButtonsLayout->addWidget(button);
        connect(button, &QPushButton::clicked, this, [=]() {
            onShapeButtonClicked(m_shapeTypes[i]);
        });
    }
    m_shapeButtonsLayout->addStretch();

    m_rightLayout = new QVBoxLayout();

    m_controlsLayout = new QHBoxLayout();
    m_controlsLayout->addWidget(new QLabel("Pen Width:"));
    m_controlsLayout->addWidget(m_penWidthEdit);
    m_controlsLayout->addWidget(new QLabel("Pen Color:"));
    m_controlsLayout->addWidget(m_penColorEdit);
    m_controlsLayout->addWidget(new QLabel("Brush Color:"));
    m_controlsLayout->addWidget(m_brushColorEdit);

    m_rightLayout->addLayout(m_controlsLayout);
    m_rightLayout->addWidget(m_drawArea, 1);

    m_mainLayout->addLayout(m_shapeButtonsLayout);
    m_mainLayout->addLayout(m_rightLayout, 1);

    setLayout(m_mainLayout);
}

void MainWindow::onShapeButtonClicked(DrawArea::ShapeType shape) {
    m_drawArea->setShape(shape);
    m_drawArea->setPenWidth(m_penWidthEdit->text().toInt());
    m_drawArea->setPenColor(QColor(m_penColorEdit->text()));
    m_drawArea->setBrushColor(QColor(m_brushColorEdit->text()));
    m_drawArea->update();
}

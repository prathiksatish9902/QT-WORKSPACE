#include "mainwindow.h"
#include "drawarea.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    drawArea = new DrawArea(this);
    penWidthEdit = new QLineEdit("2", this);
    penColorEdit = new QLineEdit("black", this);
    brushColorEdit = new QLineEdit("white", this);

    // Main horizontal layout
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // Left: shape buttons in a vertical layout
    QVBoxLayout *shapeButtonsLayout = new QVBoxLayout();
    QList<DrawArea::ShapeType> shapeTypes = {
        DrawArea::ShapeType::Circle,
        DrawArea::ShapeType::Rectangle,
        DrawArea::ShapeType::Square,
        DrawArea::ShapeType::Pentagon,
        DrawArea::ShapeType::Line,
        DrawArea::ShapeType::CurvedLine
    };
    QStringList shapeNames = {"Circle", "Rectangle", "Square", "Pentagon", "Line", "CurvedLine"};

    for (int i = 0; i < shapeTypes.size(); ++i) {
        QPushButton *button = new QPushButton(shapeNames[i], this);
        shapeButtonsLayout->addWidget(button);
        connect(button, &QPushButton::clicked, this, [=]() {
            onShapeButtonClicked(shapeTypes[i]);
        });
    }
    shapeButtonsLayout->addStretch(); // Push buttons to the top

    // Right: controls at top, draw area below
    QVBoxLayout *rightLayout = new QVBoxLayout();

    // Controls (text fields) in a horizontal layout
    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->addWidget(new QLabel("Pen Width:"));
    controlsLayout->addWidget(penWidthEdit);
    controlsLayout->addWidget(new QLabel("Pen Color:"));
    controlsLayout->addWidget(penColorEdit);
    controlsLayout->addWidget(new QLabel("Brush Color:"));
    controlsLayout->addWidget(brushColorEdit);

    rightLayout->addLayout(controlsLayout);
    rightLayout->addWidget(drawArea, 1); // Give drawArea all remaining space

    // Add left and right layouts to main layout
    mainLayout->addLayout(shapeButtonsLayout);
    mainLayout->addLayout(rightLayout, 1); // Right layout expands

    setLayout(mainLayout);
}

void MainWindow::onShapeButtonClicked(DrawArea::ShapeType shape) {
    drawArea->setShape(shape);
    drawArea->setPenWidth(penWidthEdit->text().toInt());
    drawArea->setPenColor(QColor(penColorEdit->text()));
    drawArea->setBrushColor(QColor(brushColorEdit->text()));
    drawArea->update(); // Ensure repaint
}

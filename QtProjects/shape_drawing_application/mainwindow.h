#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "drawarea.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onShapeButtonClicked(DrawArea::ShapeType shape);

private:
    DrawArea *m_drawArea;
    QLineEdit *m_penWidthEdit;
    QLineEdit *m_penColorEdit;
    QLineEdit *m_brushColorEdit;
    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_shapeButtonsLayout;
    QVBoxLayout *m_rightLayout;
    QHBoxLayout *m_controlsLayout;
    QList<DrawArea::ShapeType> m_shapeTypes;
    QStringList m_shapeNames;
};

#endif // MAINWINDOW_H

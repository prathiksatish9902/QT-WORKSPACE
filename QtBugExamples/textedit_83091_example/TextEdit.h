#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>
#include <QTextEdit>
#include <QComboBox>

class TextEdit : public QMainWindow {
    Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);

private slots:
    void textStyle(int index);

private:
    QTextEdit *textEdit;
    QComboBox *styleCombo;
};

#endif // TEXTEDIT_H

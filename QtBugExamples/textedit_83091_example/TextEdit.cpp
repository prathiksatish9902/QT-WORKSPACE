#include "TextEdit.h"
#include <QVBoxLayout>
#include <QTextListFormat>

TextEdit::TextEdit(QWidget *parent) : QMainWindow(parent) {
    // Set up the UI
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create QTextEdit
    textEdit = new QTextEdit(this);
    layout->addWidget(textEdit);

    // Create QComboBox for list styles
    styleCombo = new QComboBox(this);
    styleCombo->addItem("Standard");
    styleCombo->addItem("Bullet List (Disc)");
    styleCombo->addItem("Numbered List (Decimal)");
    layout->addWidget(styleCombo);

    // Connect combo box signal to slot
    connect(styleCombo, QOverload<int>::of(&QComboBox::activated), this, &TextEdit::textStyle);
}

void TextEdit::textStyle(int index) {
    QTextCursor cursor = textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::BlockUnderCursor);

    QTextListFormat::Style style;
    QTextBlockFormat bfmt;

    if (index == 0) {
        // Bug: Setting object index to -1 does not remove list formatting
        bfmt.setObjectIndex(-1); // This is the buggy line
    } else {
        // Apply list formatting
        switch (index) {
        case 1:
            style = QTextListFormat::ListDisc;
            break;
        case 2:
            style = QTextListFormat::ListDecimal;
            break;
        default:
            return;
        }
        QTextListFormat listFmt;
        listFmt.setStyle(style);
        cursor.createList(listFmt);
        return;
    }

    // Apply block format to remove list (buggy)
    // cursor.setBlockFormat(bfmt);
    // textEdit->setTextCursor(cursor);
}

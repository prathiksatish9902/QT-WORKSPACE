#include <QApplication>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextCharFormat>
#include <QTextCursor>

class TextFinder : public QWidget {
    Q_OBJECT
public:
    TextFinder(QWidget *parent = nullptr) : QWidget(parent) {
        textEdit = new QTextEdit(this);
        lineEdit = new QLineEdit(this);
        findButton = new QPushButton("Find", this);

        // Make textEdit read-only to prevent the bug
        textEdit->setReadOnly(true);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(textEdit);
        layout->addWidget(lineEdit);
        layout->addWidget(findButton);

        textEdit->setText("Sample text to search. Find me!");

        connect(findButton, &QPushButton::clicked, this, &TextFinder::findText);
    }

private slots:
    void findText() {
        QString searchText = lineEdit->text();
        QTextCursor cursor = textEdit->textCursor();
        QTextCharFormat highlightFormat;
        highlightFormat.setBackground(Qt::yellow);

        // Clear previous highlights
        QTextCharFormat plainFormat;
        plainFormat.setBackground(Qt::transparent);
        cursor.select(QTextCursor::Document);
        cursor.setCharFormat(plainFormat);

        // Highlight matches
        QString text = textEdit->toPlainText();
        int pos = 0;
        while ((pos = text.indexOf(searchText, pos, Qt::CaseInsensitive)) != -1) {
            cursor.setPosition(pos);
            cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, searchText.length());
            cursor.setCharFormat(highlightFormat);
            pos += searchText.length();
        }
    }

private:
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *findButton;
};

// Add the main function
int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // Initialize the Qt application
    TextFinder window;           // Create the TextFinder widget
    window.show();               // Show the widget
    return app.exec();           // Start the Qt event loop
}

#include "textfinder.moc" // Required for Qt's meta-object compiler (moc)

#include <QTextDocument>
#include <QTextCharFormat>
#include <QTextCursor> // Added missing header
#include <QFont>
#include <QDebug>

int main() {
    QTextDocument doc;

    // Insert text with default formatting
    doc.setPlainText("Hello World");

    // Apply custom letter-spacing to "World"
    QTextCursor cursor(&doc);
    cursor.setPosition(6); // Move to start of "World"
    cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor); // Select "World"
    QTextCharFormat format;
    format.setFontLetterSpacingType(QFont::AbsoluteSpacing); // Use pixel-based spacing
    format.setFontLetterSpacing(2.0); // Set letter-spacing to 2 pixels
    cursor.mergeCharFormat(format);

    // Convert to HTML
    QString html = doc.toHtml();
    qDebug() << html;

    return 0;
}

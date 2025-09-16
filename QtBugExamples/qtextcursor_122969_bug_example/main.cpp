#include <QApplication>
#include <QDebug>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit w;
    w.setPlainText("abcdef");
    QTextCursor tc = w.textCursor();

    // Select first three characters
    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, 2);
    qInfo() << "Position after selection:" << tc.position() << "Selected text:" << tc.selectedText();
    // Expected: Position = 3, Selected text = "abc"

    // Attempt to move cursor one character forward
    // tc.clearSelection();
    tc.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor);
    qInfo() << "Position after move:" << tc.position() << "Selected text:" << tc.selectedText();
    // Expected: Position = 4, Selected text = ""
    // Actual: Position = 3, Selected text = ""

    w.setTextCursor(tc);
    w.show();
    return a.exec();
}

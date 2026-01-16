
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QElapsedTimer>
#include <QLineEdit>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr)
        : QWidget(parent), counter(0)
    {
        QVBoxLayout *layout = new QVBoxLayout(this);

        statusLabel = new QLabel("Running...", this);
        layout->addWidget(statusLabel);

        QPushButton *stopButton = new QPushButton("Stop Work", this);
        layout->addWidget(stopButton);

        QLineEdit *input = new QLineEdit(this);
        layout->addWidget(input);

        // BAD: Using a 0ms timer to simulate continuous work
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MyWidget::doHeavyWork);
        timer->start(0); // <--- BAD PRACTICE

        connect(stopButton, &QPushButton::clicked, timer, &QTimer::stop);
    }

private slots:
    void doHeavyWork() {
        // Simulate heavy work by doing a busy loop
        QElapsedTimer t;
        t.start();
        while (t.elapsed() < 200) {
            // Artificial delay to simulate CPU-heavy work (200ms)
        }

        counter++;
        statusLabel->setText(QString("Processed %1 items").arg(counter));
    }

private:
    QLabel *statusLabel;
    QTimer *timer;
    int counter;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();


    return app.exec();
}
// https://chatgpt.com/c/6875dc72-c290-800d-be0e-7298e3e89e77

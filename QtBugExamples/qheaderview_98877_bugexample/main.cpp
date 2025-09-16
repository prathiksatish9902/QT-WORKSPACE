// #include <QApplication>
// #include <QTableView>
// #include <QStandardItemModel>
// #include <QHeaderView>
// #include <QHoverEvent>
// #include <QDebug>

// class MyTableView : public QTableView {
// public:
//     MyTableView(QWidget *parent = nullptr) : QTableView(parent) {
//         setMouseTracking(true);  // Needed to receive hover events
//         viewport()->setAttribute(Qt::WA_Hover);
//     }

// protected:
//     bool event(QEvent *event) override {
//         qDebug()<<"hi";
//         if (event->type() == QEvent::HoverMove) {
//             qDebug()<<"bye";
//             auto *hoverEvent = static_cast<QHoverEvent *>(event);

//             QPointF floatPos = hoverEvent->position();
//             // BUG: QHeaderView has no overload for QPointF
//             // Must convert manually — this is the bug
//             // int logicalIndex = horizontalHeader()->logicalIndexAt(floatPos.toPoint());
//             int logicalIndex = horizontalHeader()->logicalIndexAt(floatPos);

//             qDebug() << "Hovered header index:" << logicalIndex;
//         }
//         return QTableView::event(event);
//     }
// };

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);

//     MyTableView table;
//     QStandardItemModel model(4, 4);
//     table.setModel(&model);
//     table.show();

//     return app.exec();
// }




















// #include <QApplication>
// #include <QTableView>
// #include <QStandardItemModel>
// #include <QHoverEvent>
// #include <QHeaderView>
// #include <QDebug>

// class HoverableTableView : public QTableView
// {
// public:
//     HoverableTableView(QWidget *parent = nullptr) : QTableView(parent)
//     {
//         setAttribute(Qt::WA_Hover);
//     }

// protected:
//     bool event(QEvent *event) override
//     {
//         if (event->type() == QEvent::HoverMove) {
//             auto *hoverEvent = static_cast<QHoverEvent *>(event);

//             QPointF posF = hoverEvent->position();

//             // ❌ This line will not compile without the fix
//             int logicalIndex = horizontalHeader()->logicalIndexAt(posF);

//             qDebug() << "Hovered at logical index:" << logicalIndex;
//         }
//         return QTableView::event(event);
//     }
// };

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     HoverableTableView table;
//     auto *model = new QStandardItemModel(1, 5, &table);
//     table.setModel(model);
//     table.show();

//     return app.exec();
// }



// #include <QApplication>
// #include <QHeaderView>
// #include <QTableView>
// #include <QStandardItemModel>
// #include <QDebug>

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);

//     QTableView tableView;
//     QStandardItemModel model(3, 3);
//     tableView.setModel(&model);

//     QHeaderView *header = tableView.horizontalHeader();
//     header->setSectionsClickable(true);
//     header->resizeSection(0, 100);
//     header->resizeSection(1, 100);
//     header->resizeSection(2, 100);

//     tableView.show();

//     QPointF floatPoint(150.5, 5.0); // Somewhere in section 1 (100-199 range)

//     // Your newly implemented method (should return logical index 1)
//     int logical = header->logicalIndexAt(floatPoint);
//     qDebug() << "Float-based logical index at" << floatPoint << "is" << logical;

//     return app.exec();
// }


// #include <QApplication>
// #include <QTableView>
// #include <QHeaderView>
// #include <QStandardItemModel>
// #include <QMouseEvent>
// #include <QDebug>

// class CustomHeaderView : public QHeaderView {
// public:
//     CustomHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr)
//         : QHeaderView(orientation, parent) {}

// protected:
//     void mousePressEvent(QMouseEvent *event) override {
//         QPointF posF = event->position();  // QPointF from mouse event
//         int logicalIndexClicked = logicalIndexAt(posF);

//         qDebug() << "Mouse clicked at position" << posF
//                  << "Logical index:" << logicalIndexClicked;

//         // Optional: Call base class to preserve normal behavior
//         QHeaderView::mousePressEvent(event);
//     }
// };

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);

//     QTableView tableView;

//     // Use our custom header that supports QPointF logic
//     CustomHeaderView *header = new CustomHeaderView(Qt::Horizontal);
//     tableView.setHorizontalHeader(header);

//     // Setup model
//     QStandardItemModel *model = new QStandardItemModel(4, 4);
//     for (int r = 0; r < 4; ++r)
//         for (int c = 0; c < 4; ++c)
//             model->setItem(r, c, new QStandardItem(QString("R%1C%2").arg(r).arg(c)));

//     tableView.setModel(model);
//     tableView.resize(600, 300);
//     tableView.show();

//     return app.exec();
// }




// #include <QApplication>
// #include <QTableView>
// #include <QHeaderView>
// #include <QStandardItemModel>
// #include <QMouseEvent>
// #include <QDebug>

// class CustomHeaderView : public QHeaderView {
// public:
//     CustomHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr)
//         : QHeaderView(orientation, parent) {}

// protected:
//     void mousePressEvent(QMouseEvent *event) override {
//         QPoint pos = event->pos();  // QPoint version
//         int logicalIndexClicked = logicalIndexAt(pos);

//         qDebug() << "Mouse clicked at position" << pos
//                  << "Logical index:" << logicalIndexClicked;

//         // Call base class to preserve default behavior
//         QHeaderView::mousePressEvent(event);
//     }
// };

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);

//     QTableView tableView;

//     // Use our custom header that uses QPoint-based index lookup
//     CustomHeaderView *header = new CustomHeaderView(Qt::Horizontal);
//     tableView.setHorizontalHeader(header);

//     // Setup model
//     QStandardItemModel *model = new QStandardItemModel(4, 4);
//     for (int r = 0; r < 4; ++r)
//         for (int c = 0; c < 4; ++c)
//             model->setItem(r, c, new QStandardItem(QString("R%1C%2").arg(r).arg(c)));

//     tableView.setModel(model);
//     tableView.resize(600, 300);
//     tableView.show();

//     return app.exec();
// }




#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QMouseEvent>
#include <QDebug>

class CustomHeaderView : public QHeaderView {
public:
    CustomHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr)
        : QHeaderView(orientation, parent) {}

protected:
    void mousePressEvent(QMouseEvent *event) override {
        QPointF posF = event->position();  // Float precision
        QPoint posI = event->pos();        // Integer precision

        int logicalIndexF = logicalIndexAt(posF); // Custom QPointF-based overload
        int logicalIndexI = logicalIndexAt(posI); // Built-in QPoint-based overload

        qDebug() << "Mouse Click Info:";
        qDebug() << "  QPointF:" << posF << "→ logicalIndexAt(QPointF):" << logicalIndexF;
        qDebug() << "  QPoint :" << posI << "→ logicalIndexAt(QPoint) :" << logicalIndexI;

        QHeaderView::mousePressEvent(event); // Preserve default behavior
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QTableView tableView;

    // Use custom header
    CustomHeaderView *header = new CustomHeaderView(Qt::Horizontal);
    tableView.setHorizontalHeader(header);

    // Setup model
    QStandardItemModel *model = new QStandardItemModel(4, 4);
    for (int r = 0; r < 4; ++r)
        for (int c = 0; c < 4; ++c)
            model->setItem(r, c, new QStandardItem(QString("R%1C%2").arg(r).arg(c)));

    tableView.setModel(model);
    tableView.resize(600, 300);
    tableView.show();

    return app.exec();
}


























// void tst_QHeaderView::logicalIndexAtQPointF()
// {
//     QCOMPARE(view->logicalIndexAt(QPointF(-1.0, 0.0)), -1);
//     QCOMPARE(view->logicalIndexAt(QPointF(99999.0, 0.0)), -1);
//     QCOMPARE(view->logicalIndexAt(QPointF(0.0, 0.0)), 0);
//     QCOMPARE(view->logicalIndexAt(QPointF(1.0, 0.0)), 0);

//     topLevel->show();
//     QVERIFY(QTest::qWaitForWindowExposed(topLevel));
//     view->setStretchLastSection(true);

//     QCOMPARE(view->logicalIndexAt(QPointF(0.5, 0.0)), 0);
//     QCOMPARE(view->logicalIndexAt(QPointF(0.9, 0.0)), 0);

//     QCOMPARE(view->logicalIndexAt(QPointF(0.0, 0.0)), 0);
//     QCOMPARE(view->logicalIndexAt(QPointF(view->sectionSize(0) - 1.0, 0.0)), 0);
//     QCOMPARE(view->logicalIndexAt(QPointF(view->sectionSize(0) + 1.0, 0.0)), 1);

//     double sectionMid = view->sectionSize(0) / 2.0;
//     QCOMPARE(view->logicalIndexAt(QPointF(sectionMid, 0.0)), 0);
//     QCOMPARE(view->logicalIndexAt(QPointF(sectionMid + 0.3, 0.0)), 0);
//     QCOMPARE(view->logicalIndexAt(QPointF(sectionMid + 0.7, 0.0)), 0);

//     double last = view->length() - 1.0;
//     QCOMPARE(view->logicalIndexAt(QPointF(last, 0.0)), 3);
//     QCOMPARE(view->logicalIndexAt(QPointF(last - 0.5, 0.0)), 3);

//     double outofbounds = view->length() + 1.0;
//     QCOMPARE(view->logicalIndexAt(QPointF(outofbounds, 0.0)), -1);
//     QCOMPARE(view->logicalIndexAt(QPointF(outofbounds + 0.5, 0.0)), -1);

//     view->moveSection(0, 1);

//     QCOMPARE(view->logicalIndexAt(QPointF(0.0, 0.0)), 1);
//     QCOMPARE(view->logicalIndexAt(QPointF(0.5, 0.0)), 1);
//     QCOMPARE(view->logicalIndexAt(QPointF(view->sectionSize(0) - 1.0, 0.0)), 1);
//     QCOMPARE(view->logicalIndexAt(QPointF(view->sectionSize(0) + 1.0, 0.0)), 0);

//     QCOMPARE(view->logicalIndexAt(QPointF(last, 0.0)), 3);
//     QCOMPARE(view->logicalIndexAt(QPointF(last - 0.3, 0.0)), 3);

//     for (int i = 0; i < view->length(); i += 10) {
//         QPoint intPoint(i, 0);
//         QPointF floatPoint(i, 0);
//         QCOMPARE(view->logicalIndexAt(intPoint), view->logicalIndexAt(floatPoint));

//         QPointF floatPointWithFraction(i + 0.7, 0);
//         QCOMPARE(view->logicalIndexAt(intPoint), view->logicalIndexAt(floatPointWithFraction));
//     }

//     QCOMPARE(view->logicalIndexAt(QPointF(-0.5, 0.0)), -1);
//     QCOMPARE(view->logicalIndexAt(QPointF(-0.1, 0.0)), -1);

//     QCOMPARE(view->logicalIndexAt(QPointF(99999.9, 0.0)), -1);
//     QCOMPARE(view->logicalIndexAt(QPointF(99999.1, 0.0)), -1);

//     view->moveSection(1, 0);
// }

// Also add this to your test class header file (tst_qheaderview.h):
// private slots:
//     void logicalIndexAtQPointF();

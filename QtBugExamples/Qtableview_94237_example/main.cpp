#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QTableView tableView;
    QStandardItemModel model(5, 3); // 5 rows, 3 columns

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 3; ++col) {
            model.setItem(row, col, new QStandardItem(QString("R%1C%2").arg(row).arg(col)));
        }
    }

    tableView.setModel(&model);
    tableView.horizontalHeader()->setSectionsMovable(true); // Enable header reordering
    tableView.show();

    return app.exec();
}

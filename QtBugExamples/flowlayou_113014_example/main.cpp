#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QLayout>
#include <QSize>
#include <QList>

// FlowLayout implementation (simplified from Qt example)
class FlowLayout : public QLayout
{
public:
    FlowLayout(QWidget *parent, int margin = -1, int hSpacing = -1, int vSpacing = -1)
        : QLayout(parent)
    {
        setContentsMargins(margin, margin, margin, margin);
        m_hSpace = hSpacing;
        m_vSpace = vSpacing;
    }

    ~FlowLayout()
    {
        qDeleteAll(m_itemList);
    }

    void addItem(QLayoutItem *item) override
    {
        m_itemList.append(item);
    }

    int horizontalSpacing() const
    {
        return m_hSpace >= 0 ? m_hSpace : 6; // Default spacing
    }

    int verticalSpacing() const
    {
        return m_vSpace >= 0 ? m_vSpace : 6; // Default spacing
    }

    int count() const override
    {
        return m_itemList.size();
    }

    QLayoutItem *itemAt(int index) const override
    {
        return m_itemList.value(index);
    }

    QLayoutItem *takeAt(int index) override
    {
        if (index >= 0 && index < m_itemList.size())
            return m_itemList.takeAt(index);
        return nullptr;
    }

    QSize minimumSize() const override
    {
        QSize size;
        for (const QLayoutItem *item : m_itemList)
            size = size.expandedTo(item->minimumSize());
        size += QSize(contentsMargins().left() + contentsMargins().right(),
                      contentsMargins().top() + contentsMargins().bottom());
        return size;
    }

    QSize sizeHint() const override
    {
        return minimumSize(); // Buggy implementation
    }

    void setGeometry(const QRect &rect) override
    {
        int left, top, right, bottom;
        getContentsMargins(&left, &top, &right, &bottom);
        QRect effectiveRect = rect.adjusted(left, top, -right, -bottom);
        int x = effectiveRect.x();
        int y = effectiveRect.y();
        int lineHeight = 0;

        for (QLayoutItem *item : m_itemList)
        {
            QWidget *wid = item->widget();
            int spaceX = horizontalSpacing();
            int spaceY = verticalSpacing();
            QSize itemSize = item->sizeHint();

            if (x + itemSize.width() > effectiveRect.right() && lineHeight > 0)
            {
                x = effectiveRect.x();
                y += lineHeight + spaceY;
                lineHeight = 0;
            }

            item->setGeometry(QRect(QPoint(x, y), itemSize));
            x += itemSize.width() + spaceX;
            lineHeight = qMax(lineHeight, itemSize.height());
        }
    }

private:
    QList<QLayoutItem *> m_itemList;
    int m_hSpace;
    int m_vSpace;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(window);

    QScrollArea *scrollArea = new QScrollArea;
    QWidget *scrollWidget = new QWidget;
    FlowLayout *flowLayout = new FlowLayout(scrollWidget, 10, 5, 5);

    // Add buttons to FlowLayout
    for (int i = 0; i < 10; ++i)
    {
        QPushButton *button = new QPushButton(QString("Button %1").arg(i + 1));
        button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        flowLayout->addWidget(button);
    }

    scrollWidget->setLayout(flowLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);
    mainLayout->addWidget(scrollArea);

    window->resize(300, 200);
    window->show();

    return app.exec();
}

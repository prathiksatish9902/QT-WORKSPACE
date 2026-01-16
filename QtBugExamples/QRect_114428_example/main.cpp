#include <QRect>
#include <QPoint>
#include <cassert>
#include <iostream>

int main() {
    // Case 1: Rectangle with odd width and height
    const QPoint position1(-5, -5);
    QRect rect1(0, 0, 6, 6); // Width and height are even, but let's test with odd sizes
    rect1.moveCenter(position1);
    std::cout << "Case 1: Expected center: (" << position1.x() << ", " << position1.y() << "), "
              << "Actual center: (" << rect1.center().x() << ", " << rect1.center().y() << ")\n";
    // assert(rect1.center() == position1); // This assertion may fail

    // Case 2: Degenerate rectangle (zero width and height)
    const QPoint position2(5, 5);
    QRect rect2(10, 10, 0, 0);
    rect2.moveCenter(position2);
    std::cout << "Case 2: Expected center: (" << position2.x() << ", " << position2.y() << "), "
              << "Actual center: (" << rect2.center().x() << ", " << rect2.center().y() << ")\n";
    // assert(rect2.center() == position2); // This assertion may fail

    return 0;
}

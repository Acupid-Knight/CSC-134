
// RectangleValidated.cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    void setLength(double l) {
        if (l > 0)
            length = l;
    }

    void setWidth(double w) {
        if (w > 0)
            width = w;
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double getArea() const {
        return length * width;
    }
};

int main() {
    Rectangle box;
    double rectLength, rectWidth;

    do {
        cout << "Enter the length (positive): ";
        cin >> rectLength;
    } while (rectLength <= 0);

    do {
        cout << "Enter the width (positive): ";
        cin >> rectWidth;
    } while (rectWidth <= 0);

    box.setLength(rectLength);
    box.setWidth(rectWidth);

    cout << "Area: " << box.getArea() << endl;

    return 0;
}

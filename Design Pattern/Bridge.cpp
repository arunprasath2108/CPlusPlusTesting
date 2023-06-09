#include <iostream>

class Color {
    public:
    virtual void applyColor() = 0;
};

class RedColor : public Color {

    public:
    void applyColor() {
        std::cout << "Red color." << std::endl;
    }
};

class BlueColor : public Color {

    public:
    void applyColor() {
        std::cout << "Blue color." << std::endl;
    }
};

class Shape {

    public:
    virtual void applyColor() = 0;

    void print() {
        std::cout << "draw a circle with ";
    }
};

class Circle : public Shape {

    Color* color;

    public:
    Circle(Color* color) {
        this->color = color;
    }

    void applyColor() {
        print();
        color->applyColor();
    }
};

int main() {

    Color* red = new RedColor();
    Shape* circle = new Circle(red);
    circle->applyColor();
    Color* blue = new BlueColor();
    Shape* circle1 = new Circle(blue);
    circle1->applyColor();
}
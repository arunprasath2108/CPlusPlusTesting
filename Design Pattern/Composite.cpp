#include <iostream>
#include <vector>

class Shape {
	
    public :
	virtual void draw(std::string) = 0;
};

//part object
class Triangle: public Shape {

    public :
	void draw(std::string fillColor) {
		std::cout << "Drawing Triangle with the color " << fillColor << std::endl;
	}
};

class Circle: public Shape {

    public :
	void draw(std::string fillColor) {
		std::cout << "Drawing Circle with the color " << fillColor << std::endl;
	}
};

//whole object
class Draw: public Shape {

	std::vector<Shape*> shapes;
	
    public:
	void draw(std::string fillColor) {
		for(Shape* shape : shapes)
		{
			shape->draw(fillColor);
		}
	}
	
    void addShape(Shape* sh) {
        shapes.push_back(sh);
    }
	
	void removeShape(Shape* s){

        auto it = std::find(shapes.begin(), shapes.end(), s);
        if (it != shapes.end()) {
             shapes.erase(it);
        }
	}
	
	void clear() {
		std::cout << "delete all shapes from draw" << std::endl;
		shapes.clear();
	}
};

int main() {

    Shape* triangle = new Triangle();
    Shape* circle = new Circle();

    Draw* drawings = new Draw();
    drawings->addShape(triangle);
    drawings->addShape(circle);

    drawings->draw("red");
}
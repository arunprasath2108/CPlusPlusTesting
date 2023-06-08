#include <iostream>
#include <map>

class PaintBrush {

    public:
    virtual void setColor(std::string) = 0;
    virtual void paint() = 0;
};

class ThickBrush : public PaintBrush {

    std::string color;
    public:
    void setColor(std::string color) {
        this->color = color;
    }

    void paint() {
        std::cout << "Painting the wall with " << color << " color." << std::endl;
    }
};

class ThinBrush : public PaintBrush {

    std::string color;
    public:
    void setColor(std::string color) {
        this->color = color;
    }

    void paint() {
        std::cout << "Painting the wall with " << color << " color." << std::endl;
    }
};

class MediumBrush : public PaintBrush {

    std::string color;
    public:
    void setColor(std::string color) {
        this->color = color;
    }

    void paint() {
        std::cout << "Painting the wall with " << color << " color." << std::endl;
    }
};

class BrushFactory {

    std::map<std::string, PaintBrush*> brushMap;

    public:
    PaintBrush* getThickBrush(std::string color) {
        std::string key = color + " - Thick";

        if(brushMap.find(key) == brushMap.end()) {
            PaintBrush* thickBrush = new ThickBrush();
            thickBrush->setColor(color);
            brushMap.insert(std::pair<std::string, PaintBrush*>(key, thickBrush));
        }
        return brushMap[key];
    }

    PaintBrush* getThinBrush(std::string color) {
        std::string key = color + " - Thin";

        if(brushMap.find(key) == brushMap.end()) {
            PaintBrush* thinBrush = new ThinBrush();
            thinBrush->setColor(color);
            brushMap.insert(std::pair<std::string, PaintBrush*>(key, thinBrush));
        }
        return brushMap[key];
    }

    PaintBrush* getMediumBrush(std::string color) {
        std::string key = color + " - Medium";

        if(brushMap.find(key) == brushMap.end()) {
            PaintBrush* mediumBrush = new ThinBrush();
            mediumBrush->setColor(color);
            brushMap.insert(std::pair<std::string, PaintBrush*>(key, mediumBrush));
        }
        return brushMap[key];
    }
};

int main() {

    BrushFactory brushFactory;
    PaintBrush* redBrush = brushFactory.getThickBrush("RED");
    PaintBrush* whiteBrush = brushFactory.getThinBrush("WHITE");
    PaintBrush* yellowBrush = brushFactory.getMediumBrush("YELLOW");

    //reuse
    PaintBrush* whiteBrush1 = brushFactory.getThinBrush("WHITE");
    PaintBrush* redBrush1 = brushFactory.getThickBrush("RED");

    redBrush->paint();
    whiteBrush->paint();
    yellowBrush->paint();

    whiteBrush1->paint();
    redBrush1->paint();
}

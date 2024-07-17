#include <iostream>
#include <string>

const float pi = acos(-1);

class Point
{
private:
    float x;
    float y;
public:
    Point() = default;
    Point(float a, float b) {
        x = a;
        y = b;
    }
    const void getPoint() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

class Figure
{
private:
    std::string color;
    std::string type;
    float radius;
    Point center;
public:
    Figure() = default;
    Figure(std::string t, std::string c, float r, Point ct) {
        type = t;
        color = c;
        radius = r;
        center = ct;
    }
    const std::string& GetType() const {
        return type;
    }
    const std::string& GetColor() const {
        return color;
    }
    const float& GetR() const {
        return radius;
    }
    const void GetCenter() const {
        center.getPoint();
    }
    virtual void Info() const = 0;
    virtual float GetSquare() const = 0;
    virtual float GetPerimeter() const = 0;
};

class Sector : public Figure
{
private:
    float alpha;
public:
    Sector() = default; 
    Sector(std::string c, float r, Point ct, float a) : Figure("Сектор", c, r, ct) {
        alpha = a;
    }
    void Info() const override {
        std::cout << "Угол: " << alpha;
    }
    float GetSquare() const override {
        return GetR()*GetR()*alpha/2;
    }
    float GetPerimeter() const override{
        return GetR() * (alpha + 2);
    }
};

class Polygon : public Figure
{
private:
    int K;
public:
    Polygon() = default;
    Polygon(std::string c, float r, Point ct, int k) : Figure("Правильный многоугольник", c, r, ct) {
        K = k;
    }
    void Info() const override {
        std::cout << "Кол-во углов: " << K;
    }
    float GetSquare() const override {
        return GetR() * GetR() * K * sin(2*pi/K) / 2;
    }
    float GetPerimeter() const override {
        return 2*GetR() * K * sin(pi / K);
    }
};

void FigureInfo(const Figure& figure) {
    std::cout << "\nТип: " << figure.GetType();
    std::cout << "\nЦвет: " << figure.GetColor();
    std::cout << "\nРадиус: " << figure.GetR();
    std::cout << "\nЦентр: ";
    figure.GetCenter();
    figure.Info();
    std::cout << "\nПлощадь: " << figure.GetSquare();
    std::cout << "\nПериметр: " << figure.GetPerimeter() << std::endl;
}

int main()
{
    setlocale(0, "");
    Figure** figures{ new Figure*[4] };
    figures[0] = new Sector("Красный", 10, Point(10, 10), pi/2);
    figures[1] = new Polygon("Синий", 10, Point(0, 0), 4);
    FigureInfo(*figures[0]);
    FigureInfo(*figures[1]);
}


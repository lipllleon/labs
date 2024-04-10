#include <SFML/Graphics.hpp>
#include <Figure.hpp>
#include <Trapezoid.hpp>
#include <Ellipse.hpp>

class point
{
private:
	double x;
	double y;
public:
	point() = default;
	point(double a, double b)
	{
		x = a;
		y = b;
	}
	/*void setCentalPoint(int n, int width, int heigth)
	{
		x = n * width / 3;
		y = heigth / 2;
	}*/
	void set_x(double a)
	{
		x = a;
	}
	void set_y(double b)
	{
		y = b;
	}
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
};

class Figure
{
public:

	double lenVec(point a, point b)
	{
		return sqrt(pow((a.get_x() - b.get_x()), 2) + pow((a.get_y() - b.get_y()), 2));
	}
};

class Ellipse : public Figure
{
private:
	point O;
	point A;
	point B;
	double a;
	double b;
	sf::CircleShape circle_;
public:
	Ellipse(point o, point aa, point bb)
	{
		O = o;
		A = aa;
		B = bb;
		a = lenVec(aa, o);
		b = lenVec(bb, o);
		circle_ = sf::CircleShape(b);
		circle_.setScale(static_cast<float>(a/b), 1);
		circle_.setPosition(500, 300);
		circle_.setFillColor(sf::Color::Black);
	}

	sf::CircleShape get_ellipse()
	{
		return circle_;
	}

};

int main()
{
	sf::RenderWindow window;
	int width = 1000;
	int height = 600;
	window.create(sf::VideoMode(width, height), "game");

	Ellipse shape(point(0, 0), point(100, 0), point(0, 50));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		window.draw(shape.get_ellipse());
		window.display();
	}
}
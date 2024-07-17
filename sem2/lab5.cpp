#include <iostream>

const float pi = acos(-1);

class R_Complex
{
private:
    float r;
    float y;

public:
    R_Complex() = default;
    R_Complex(float a, float alpha)
    {
        r = a;
        y = alpha;
    }
    R_Complex(R_Complex& other)
    {
        r = other.r;
        y = other.y;
    }
    ~R_Complex() {
        std::cout << "Комплексное число: " << "(" << r << ", " << y << ") удалено\n";
    }

    R_Complex& operator =(R_Complex& other)
    {
        this->r = other.r;
        this->y = other.y;
        return *this;
    }
    R_Complex& operator +=(R_Complex& other)
    {
        r = sqrt(this->r * this->r + other.r * other.r + 2 * this->r * other.r * cos(abs(this->y - other.y)));
        float tan = (this->r * sin(this->y) + other.r * sin(other.y)) / (this->r * cos(this->y) + other.r * cos(other.y)); //b1+b2 / a1+a2
        if ((this->r * cos(this->y) + other.r * cos(other.y)) == 0) // a1+a2
            if ((this->r * sin(this->y) + other.r * sin(other.y)) > 0) //b1+b2
                y = pi / 2;
            else
                y = 3*pi/2
        else {
            y = atan(tan);
              if ((this->r * cos(this->y) + other.r * cos(other.y)) < 0) //a1+a2
                y += pi;
        }
        return *this;
    }
    R_Complex& operator +(const R_Complex& other) 
    {
        R_Complex temp(sqrt(this->r*this->r + other.r*other.r + 2*this->r*other.r*cos(abs(this->y - other.y))), atan((this->r*sin(this->y) + other.r*sin(other.y))/(this->r * cos(this->y) + other.r * cos(other.y))));
        return temp;
    }
    R_Complex& operator *=(R_Complex& other)
    {
        r = this->r * other.r;
        y = this->y + other.y;
        return *this;
    }
    R_Complex& operator *(const R_Complex& other)
    {
        R_Complex temp(this->r * other.r, this->y + other.y);
        return temp;
    }
    R_Complex& operator++()
    {
        r++;
        return *this;
    }
    R_Complex& operator++(int value)
    {
        R_Complex temp(*this);
        this->r++;
        return temp;
    }



    float get_r()
    {
        return this->r;
    }
    float get_y()
    {
        return this->y;
    }

    void print()
    {
        std::cout << "(" << r << ", " << y << ")\n";
    }
};

void print(R_Complex& c)
{
    c.print();
}

float scalarC(R_Complex& a, R_Complex& b)
{
    return a.get_r() * b.get_r() * cos(abs(a.get_y() - b.get_y()));
}

R_Complex& absC(R_Complex& a, R_Complex& b)
{
    if (a.get_r() >= b.get_r())
        return a;
    else
        return b;
}

int qC(R_Complex& a)
{
    if (a.get_r() == 0)
        return 1;
    float alpha = a.get_y();
    while (alpha >= 2 * pi)
        alpha -= 2 * pi;
    while (alpha < 0)
        alpha += 2 * pi;
    
    if (alpha < pi)
        if (alpha < pi / 2)
            return 1;
        else
            return 2;
    else
        if (alpha < 3 * pi / 2)
            return 3;
        else
            return 4;
}

int main()
{
    setlocale(0, "");
    R_Complex a(4, 3*pi/4);
    R_Complex b(3, pi/3);
    print(a);
    print(b);
    R_Complex c;
    c = b++;
    print(b);
    print(c);
    a.operator+=(b);
    print(a);
    R_Complex d;
    d = a + c;
    print(d);

    std::cout << "\n\nСкалярное произведение комплексных чисел: ";
    print(a);
    print(b);
    std::cout << "= " << scalarC(a, b) << std::endl;;

    d = absC(a, b);
    std::cout << "\n\nМаксимальное по модулю из чисел: ";
    print(a);
    print(b);
    std::cout << "= ";
    print(d);

    std::cout << "\n\nКвадрант комплексного числа: ";
    print(a);
    std::cout << qC(a) << std::endl;
}
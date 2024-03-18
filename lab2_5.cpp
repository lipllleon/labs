#include <iostream>

class D_Complex 
{
private:
    int a;
    int b;

public:
    D_Complex() = default;
    D_Complex(int x)
    {
        a = x;
        b = 0;
    }
    D_Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    D_Complex(D_Complex& c)
    {
        a = c.a;
        b = c.b;
    }
    ~D_Complex() {
        std::cout << "Комплексное число: " << "(" << a << ", " << b << ") удалено\n";
    }

    D_Complex& operator +=(D_Complex& other)
    {
        a += other.a;
        b += other.b;
        return *this;
    }
    D_Complex operator +(const D_Complex& other) {
        D_Complex temp(this->a + other.a, this->b + other.b);
        return temp;
    }
    D_Complex& operator -=(D_Complex& other)
    {
        a -= other.a;
        b -= other.b;
        return *this;
    }
    D_Complex operator -(const D_Complex& other) {
        D_Complex temp(this->a - other.a, this->b - other.b);
        return temp;
    }
    D_Complex& operator++()
    {
        a++;
        return *this;
    }
    D_Complex& operator++(int value)
    {
        D_Complex temp(*this);
        this->a++;
        return temp;
    }
    void print()
    {
        std::cout << "(" << a << ", " << b << ")\n";
    }
};

void print(D_Complex& c)
{
    c.print();
}

int main()
{
    setlocale(0, "");
    D_Complex a(2, 2);
    D_Complex b(3, -2);
    a.print();
    b.print();
    D_Complex c;
    c = b++;
    print(b);
    print(c);
    a += b;
    print(a);
    a -= c;
    print(a);
    D_Complex d;
    d = a + c;
    print(d);
}
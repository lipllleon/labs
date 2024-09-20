#include <iostream>

const double pi = acos(-1);

struct answer
{
    double M;
    int count;
    double E;

    answer() = default;
    answer(double mid, int c, double ep)
    {
        M = mid;
        count = c;
        E = ep;
    }
    void print()
    {
        std::cout << "Точка: " << M << std::endl;
        std::cout << "Кол-во итераций: " << count << std::endl;
        std::cout << "Погрешность: " << E << std::endl;
    }
};

double getValue(double x)
{
    //double value = 0.8 * (x + 2) - 3 * cos(0.7 * x) + 2;
    //double value = 0.7 * (sin(x / 2) + cos(2 * x)) - x;
    double value = cos(2 * x + pi / 2) + x + 8;
    return value;
}

double getMidPoint(double L, double R)
{
    double M = (L + R) / 2;

    return M;
}

bool isDifferent(double L, double R)
{
    if (((getValue(L) < 0) && (getValue(R) > 0)) || ((getValue(L) > 0) && (getValue(R) < 0)))
        return true;
    else
        return false;
}

bool inE(double M, double E)
{
    if (abs(getValue(M)) < E)
        return true;
    else
        return false;
}

std::pair <double, double> setPair(double L, double R)
{
    std::pair <double, double> range;
    range.first = L;
    range.second = R;
    return range;
}

std::pair <double, double> halfDivision(double L, double R)
{
    double M = getMidPoint(L, R);
    if (isDifferent(L, M))
        R = M;
    else
        L = M;
    return setPair(L, R);
}

answer fullHalfDivision(double L, float step, float E)
{
    double R = L + step;
    int count = 0;
    while (!isDifferent(L, R))
    {
        L += step;
        R += step;
    }
    std::pair <double, double> range;
    range = setPair(L, R);
    double M = getMidPoint(L, R);
    while (!inE(M, E))
    {
        range = halfDivision(L, R);
        L = range.first;
        R = range.second;
        M = getMidPoint(L, R);
        count++;
    }
    return answer(M, count, abs(getValue(M)));
}

int main()
{
    setlocale(0, "ru");
    double L;
    std::cout << "Введите левую границу" << std::endl;
    std::cin >> L;
    answer result = fullHalfDivision(L, 0.5, 0.001);
    result.print();
}

#include <iostream>
#include <windows.h>

const double pi = acos(-1);

struct answer {
private:
  double M;
  int count;
  double E;

public:
  answer() = default;
  answer(double mid, int c, double ep) {
    M = mid;
    count = c;
    E = ep;
  }
  void print() {
    std::cout << "Точка: " << M << std::endl;
    std::cout << "Кол-во итераций: " << count << std::endl;
    std::cout << "Погрешность: " << E << std::endl;
  }
};

double f1(double x) { return 0.8 * (x + 2) - 3 * cos(0.7 * x) + 2; }
double f2(double x) { return 0.7 * (sin(x / 2) + cos(2 * x)) - x; }
double f4(double x) { return cos(2 * x + pi / 2) + x + 8; }

double getMidPoint(double L, double R) { return (L + R) / 2; }

bool isDifferent(double (*f)(double), double L, double R) {
  if (f(L) * f(R) < 0)
    return true;
  else
    return false;
}

answer HalfDivision(double (*f)(double)) {
  double L = -10;
  float step = 0.5;
  double R = L + step;
  float E = 0.001;
  int count = 0;

  while (!isDifferent(f, L, R)) {
    L += step;
    R += step;
  }
  double M = getMidPoint(L, R);

  while (abs(f(M)) > E) {
    if (isDifferent(f, L, M))
      R = M;
    else
      L = M;
    M = getMidPoint(L, R);
    count++;
  }

  return answer(M, count, abs(f(M)));
}

int main() {
  answer result = HalfDivision(f1);
  result.print();
}

#include <iostream>

const double pi = acos(-1);

struct answer {
  double M;
  int count;
  double E;

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

double getValue(double x) {
  // double value = 0.8 * (x + 2) - 3 * cos(0.7 * x) + 2;
  // double value = 0.7 * (sin(x / 2) + cos(2 * x)) - x;
  double value = cos(2 * x + pi / 2) + x + 8;
  return value;
}

double getMidPoint(double L, double R) {
  double M = (L + R) / 2;

  return M;
}

bool isDifferent(double L, double R) {
  if (getValue(L) * getValue(R) < 0)
    return true;
  else
    return false;
}

bool inE(double M, double E) {
  if (abs(getValue(M)) < E)
    return true;
  else
    return false;
}

answer HalfDivision(double L, float step, float E) {
  double R = L + step;
  int count = 0;
  while (!isDifferent(L, R)) {
    L += step;
    R += step;
  }
  double M = getMidPoint(L, R);
  while (!inE(M, E)) {
    if (isDifferent(L, M))
      R = M;
    else
      L = M;
    M = getMidPoint(L, R);
    count++;
  }
  return answer(M, count, abs(getValue(M)));
}

int main() {
  setlocale(0, "ru");
  double L;
  std::cout << "Введите левую границу" << std::endl;
  std::cin >> L;
  answer result = HalfDivision(L, 0.5, 0.001);
  result.print();
}

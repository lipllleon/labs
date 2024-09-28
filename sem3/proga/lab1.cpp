#include <iostream>
#include <sstream>
#include <string>

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
  std::string printTable() {
    std::string space = ", ";
    std::ostringstream Mstring;
    Mstring << M;
    std::string Mstr = Mstring.str();
    std::ostringstream Estring;
    Estring << E;
    std::string Estr = Estring.str();
    std::ostringstream Cstring;
    Cstring << count;
    std::string Cstr = Cstring.str();
    std::string s = Mstr + space + Cstr + space + Estr;
    return s;
  }
};

double f1(double x) { return 0.8 * (x + 2) - 3 * cos(0.7 * x) + 2; }
double f2(double x) { return 0.7 * (sin(x / 2) + cos(2 * x)) - x; }
double f4(double x) { return cos(2 * x + pi / 2) + x + 8; }

double getMidPoint(double L, double R) { return (L + R) / 2; }

double getInterPoint(double (*f)(double), double L, double R) {
  return (L * f(R) - R * f(L)) / (f(R) - f(L));
}

bool isDifferent(double (*f)(double), double L, double R) {
  if (f(L) * f(R) < 0)
    return true;
  else
    return false;
}

double getLeftPoint(double (*f)(double), double start, float step) {
  double L = start;
  double R = L + step;
  while (!isDifferent(f, L, R)) {
    L += step;
    R += step;
  }
  return L;
}

answer halfDivisionMethod(double (*f)(double), double E) {
  int count = 1;
  float step = 0.5;
  double L = getLeftPoint(f, -10, step);
  double R = L + step;
  double M = getMidPoint(L, R);

  while (abs(f(M)) > E && count < 100) {
    if (isDifferent(f, L, M))
      R = M;
    else
      L = M;
    M = getMidPoint(L, R);
    count++;
  }

  return answer(M, count, abs(f(M)));
}

answer secantMethod(double (*f)(double), double E) {
  int count = 1;
  float step = 0.5;
  double L = getLeftPoint(f, -10, 0.5);
  double R = L + step;
  double M = getInterPoint(f, L, R);

  while (abs(f(M)) > E && count < 100) {
    if (isDifferent(f, L, M))
      R = M;
    else
      L = M;
    M = getInterPoint(f, L, R);
    count++;
  }

  return answer(M, count, abs(f(M)));
}

int main() {
  setlocale(0, "RU");
  float E = 0.001;
  halfDivisionMethod(f1, E).print();
  secantMethod(f1, E).print();

  std::cout << "              "
            << "E = 0.1"
            << "                       "
            << "E = 0.01"
            << "                         "
            << "E = 0.0001" << std::endl;
  std::cout << "Метод пол.дел." << halfDivisionMethod(f2, 0.1).printTable()
            << "          " << halfDivisionMethod(f2, 0.01).printTable()
            << "           " << halfDivisionMethod(f2, 0.0001).printTable()
            << std::endl;
  std::cout << "Метод сек.    " << secantMethod(f2, 0.1).printTable()
            << "       " << secantMethod(f2, 0.01).printTable() << "          "
            << secantMethod(f2, 0.0001).printTable() << std::endl;
}

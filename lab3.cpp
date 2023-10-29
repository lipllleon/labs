#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(0, "");
    int n, i;
    n = 176;
    cout << "Введите номер бита для 176 (10110000): ";
    cin >> i;
    n = n & ~(1 << i);
    cout << 176 << "-->" << n << endl; //176 = 10110000
    n = 55;
    cout << "Введите номер бита для 55 (110111): ";
    cin >> i;
    n = n & ~(1 << i);
    cout << 55 << "-->" << n << endl; //55 = 110111
    n = 25;
    cout << "Введите номер бита для 25 (11001): ";
    cin >> i;
    n = n & ~(1 << i);
    cout << 25 << "-->" << n; //25 = 11001
}

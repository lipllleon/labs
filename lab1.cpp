#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(0, "");
    int S;
    float h;
    cout << "Укажите площадь основания пирамиды: ";
    cin >> S;
    cout << "Укажите высоту пирамиды: ";
    cin >> h;
    cout << "Объём пирамиды: " << (S * h) / 3;
}

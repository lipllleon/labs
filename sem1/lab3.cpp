//Вариант 4
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(0, "RU");
    short p;
    cout << "Пункт задания: ";
    cin >> p;
    switch (p)
    {
    case 1:
        unsigned int a, b, c;
        cout << "Введите числа A, B, C: " << endl;
        cout << "A = ";
        cin >> a;
        cout << "B = ";
        cin >> b;
        cout << "C = ";
        cin >> c;
        if (!((a > 0) && (b > 0) && (c > 0))) {
            cout << "Не натуральное число" << endl;
        }
        else {
            if (a % b == 0) {
                cout << "А делится на В" << endl;
                if (b > c) {
                    cout << "B > C" << endl;
                    cout << (a / b + c) << "  (a / b + c)";
                }
                else if (b < c) {
                    cout << "B < C" << endl;
                    cout << (a / b - c) << "  (a / b - c)";
                }
            }
            else {
                cout << "А не делится на В" << endl;
                cout << ((a + b) * c) << "  ((a + b) * c)";
            }
        }
        break;

    case 2:
        int n;
        cout << "Введите код товара: ";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "Нефть";
            break;
        case 25:
            cout << "Сахар рафинад быстрорастворимый";
            break;
        case 30:
            cout << "Авокадо";
            break;
        case 500:
            cout << "Яблоки";
            break;
        case 645:
            cout << "Помидоры";
            break;
        case 1966:
            cout << "Апельсины";
            break;
        case 4949:
            cout << "Колбаса вареная докторская";
            break;
        default:
            cout << "Код не найден";
            break;
        }
        break;

    default:
        cout << "Неверный пункт";
        break;
    }
}

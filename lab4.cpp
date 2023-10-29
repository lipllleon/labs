#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(0, "RU");
    short count, c, punkt;
    int max, sum, x;
    std::cout << "Введите пункт задания: ";
    cin >> punkt;
    switch (punkt) {
    case 1:
        x = 1;
        max = -2147483647;
        sum = 0;
        count = 0;
        std::cout << "Введите кол-во чисел: ";
        cin >> c;
        std::cout << "Вводите числа:" << endl;;
        for (int i = 0; i < c; i++) {
            cin >> x;
            if (x < 0) {
                sum += x;
                if (x == max) {
                    count++;
                }
                else if (x > max) {
                    max = x;
                    count = 1;
                }
            }
        }
        std::cout << "Сумма отрицательных чисел = " << sum << endl;
        if (count != 0) {
            std::cout << "Наибольшее отрицательное = " << max << " встречается " << count << " раз.";
        }
        break;
    case 2:
        int m;
        max = 0;
        std::cout << "Введите число: ";
        cin >> x;
        if (abs(x) >= 1000000000) {
            std::cout << "Слишком большое число";
            break;
        }
        while (x > 0)
        {
            m = x % 10;
            if (m > max) {
                max = m;
            }
            x = x / 10;
        }
        std::cout << "Наибольшая цифра числа = " << max;
        break;
    default:
        std::cout << "Введён неверный пункт.";
        break;
    }
}

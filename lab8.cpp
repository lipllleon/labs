#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    int K, S;
    int* A;
    bool flag;
    cout << "Введите размер массива K: ";
    cin >> K;
    A = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        A[i] = i;
        cout << A[i] << " ";
    }

    cout << "\nВведите изменение размера массива S: ";
    cin >> S;

    if (K + S > 0) {
        A = (int*)realloc(A, (K + S) * sizeof(int));
        if (S >= 0) {
            flag = true;
            cout << "Введите элементы матрицы через пробел: \n";
            for (int i = 0; i < K; i++) {
                A[i] = i;
                cout << A[i] << " ";
            }
        }
        else {
            cout << "Массив урезан: ";
            flag = false;
            for (int i = 0; i < K + S; i++) {
                A[i] = i;
                cout << A[i] << " ";
            }
        }
    }
    else {
        cout << "Введено некорректное число S";
        flag = false;
    }
    if (flag) {
        int maxi, max = 0;
        for (int i = K; i < K + S; i++) {
            cin >> A[i];
            if (A[i] > max) {
                max = A[i];
                maxi = i;
            }
        }
        if (A[maxi] % 2 == 1)
            A[maxi] *= 100;
        for (int i = 0; i < K + S; i++)
            cout << A[i] << " ";
    }
    free(A);
}

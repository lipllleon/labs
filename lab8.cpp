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

    int N, M;
    cout << "\n\nВведите размеры матрицы N x M: ";
    cin >> N >> M;

    int** AA;
    AA = new int* [N];
    for (int i = 0; i < N; ++i)
        AA[i] = new int[M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            AA[i][j] = 10*(i + 1) + j + 1;
        }
    }

    cout << "Исходная матрица: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << AA[i][j] << " ";
        }
        cout << "\n";
    }

    //матричная норма 
    int max = 0;
    int sum = 0;
    for (int j = 0; j < M; j++) {
        sum = 0;
        for (int i = 0; i < N; i++)
            sum += abs(AA[i][j]);
        if (sum > max)
            max = sum;
    }
    int norm1 = max;
    cout << "Матричная норма исходной матрицы = " << norm1 << endl;

    //транспонирование
    int** B = new int* [M];
    for (int i = 0; i < M; i++)
        B[i] = new int[N];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[i][j] = AA[j][i];
        }
    }

    cout << "Транспонированная матрица: \n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }

    max = 0;
    for (int j = 0; j < N; j++) {
        sum = 0;
        for (int i = 0; i < M; i++)
            sum += abs(B[i][j]);
        if (sum > max)
            max = sum;
    }
    int norm2 = max;
    cout << "Матричная норма транспонированной матрицы = " << norm2 << endl;

    if (norm2 > norm1)
        cout << "Норма транспонированной матрицы больше исходной (" << norm2 << " > " << norm1 << ")\n";
    else if (norm1 > norm2)
        cout << "Норма исходной матрицы больше транспонированной (" << norm1 << " > " << norm2 << ")\n";
    else
        cout << "Нормы равны.\n";

    for (int i = 0; i < N; i++)
        delete[] AA[i];
    delete[] AA;
    for (int i = 0; i < M; i++)
        delete[] B[i];
    delete[] B;
    return 0;
}
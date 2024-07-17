#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    int K, S, var;
    int* A;
    bool flag;
    cout << "Введите номер варианта: ";
    cin >> var;
    if (var < 1 || var > 7) {
        cout << "Введён неверный номер варианта...\nvar = 4";
        var = 4;
    }
    cout << "Введите размер массива K: ";
    cin >> K;
    A = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        A[i] = i;
        cout << A[i] << " ";
    }

    cout << "\nВведите изменение размера массива S: ";
    cin >> S;

    if (K + S < 0) {
        cout << "Введено некорректное число S";
    } 
    else {
        A = (int*)realloc(A, (K + S) * sizeof(int));
        if (S < 0) {
            cout << "Массив урезан: ";
            for (int i = 0; i < K + S; i++)
                cout << A[i] << " ";
        }
        else {
            cout << "Введите элементы матрицы через пробел: \n";
            for (int i = 0; i < K; i++)
                cout << A[i] << " ";
            for (int i = K; i < K + S; i++)
                cin >> A[i];
            //var = 3
            int temp;
            //var = 4
            int maxi, max = 0;
            //var = 5
            int count1 = 0;
            int count0 = 0;
            switch (var)
            {
            case 1:
                for (int i = K; i < K + S; i++) {
                    if (A[i] == 0) {
                        for (int j = 0; j < K + S; j++)
                            if (A[j] % 2 == 0)
                                A[j] = 0;
                        break;
                    }
                }
                break;
            case 2:
                for (int i = K; i < K + S - 1; i++)
                    if (A[i] == A[i + 1] && (i + 2) < (K + S))
                        for (int j = i + 2; j < K + S; j++)
                            A[j] = 0;
                break;
            case 3:
                temp = 0;
                for (int i = K; i < K + S; i++) {
                    if (A[i] > 0)
                        temp++;
                    if (temp > 3) {
                        for (int j = K; j < K + S; j++)
                            if (A[j] < 0)
                                A[j] *= -1;
                        break;
                    }
                }
                break;
            case 4:
                for (int i = K; i < K + S; i++)
                    if (A[i] > max) {
                        max = A[i];
                        maxi = i;
                    }
                if (A[maxi] % 2 == 1)
                    A[maxi] *= 100;
                break;
            case 5:
                for (int i = K; i < K + S; i++)
                    if (A[i] % 2)
                        count1++;
                    else
                        count0++;
                if (count0 > count1)
                    for (int i = 0; i < K + S; i++)
                        A[i]++;
                break;
            case 6:
                for (int i = K; i < K + S; i++)
                    if (A[i] < 0) {
                        for (int j = 0; j < K + S; j++)
                            A[j] += 5;
                        break;
                    }
                break;
            case 7:
                flag = false;
                for (int i = K; i < K + S; i++)
                    if (A[i] == 1)
                        flag = true;
                if (!flag)
                    A[K + S - 1] = 999;
                break;
            default:
                break;
            }
            for (int i = 0; i < K + S; i++)
                cout << A[i] << " ";
        }
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
    int maxsum = 0;
    int sum = 0;
    for (int j = 0; j < M; j++) {
        sum = 0;
        for (int i = 0; i < N; i++)
            sum += abs(AA[i][j]);
        if (sum > maxsum)
            maxsum = sum;
    }
    int norm1 = maxsum;
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

    maxsum = 0;
    for (int j = 0; j < N; j++) {
        sum = 0;
        for (int i = 0; i < M; i++)
            sum += abs(B[i][j]);
        if (sum > maxsum)
            maxsum = sum;
    }
    int norm2 = maxsum;
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
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const unsigned short VAR = 4;

string superfunction(float** A, int N, int M, int K) {
    for (int i = 0; i < N; i++)
        if (N % 2 == 0)
            if ((i == N / 2) || (i == N / 2 - 1))
                for (int j = 0; j < M; j++)
                    if (M % 2 == 0)
                        if ((j == M / 2) || (j == M / 2 - 1))
                            A[i][j] = 0;
                        else
                            A[i][j] = K;
                    else
                        if (j == M / 2)
                            A[i][j] = 0;
                        else
                            A[i][j] = K;
            else
                for (int j = 0; j < M; j++)
                    if (M % 2 == 0)
                        if ((j == M / 2) || (j == M / 2 - 1))
                            A[i][j] = -K;
                        else
                            A[i][j] = (rand() % 201 - 100) * 0.001;
                    else
                        if (j == M / 2)
                            A[i][j] = -K;
                        else
                            A[i][j] = (rand() % 201 - 100) * 0.001;
        else
            if (i == N / 2)
                for (int j = 0; j < M; j++)
                    if (M % 2 == 0)
                        if ((j == M / 2) || (j == M / 2 - 1))
                            A[i][j] = 0;
                        else
                            A[i][j] = K;
                    else
                        if (j == M / 2)
                            A[i][j] = 0;
                        else
                            A[i][j] = K;
            else
                for (int j = 0; j < M; j++)
                    if (M % 2 == 0)
                        if ((j == M / 2) || (j == M / 2 - 1))
                            A[i][j] = -K;
                        else
                            A[i][j] = (rand() % 201 - 100) * 0.001;
                    else
                        if (j == M / 2)
                            A[i][j] = -K;
                        else
                            A[i][j] = (rand() % 201 - 100) * 0.001;
    string ABC = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string s = "";
    s += ABC[K + 4];
    s += tolower(ABC[K + 4]);
    return s;
}

void show(float** A, int N, int M) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    srand((unsigned int)time(0));
    setlocale(0, "");
    int K = VAR;
    int N = rand() % (K + 3 - K + 1) + K;
    int M = rand() % (K + 3 - K + 1) + K;
    float** A;
    A = new float* [N];
    for (int i = 0; i < N; ++i) {
        A[i] = new float[M];
    }
    ofstream fout("out.txt");
    if (!fout.is_open())
        cout << "Файл не открыт" << endl;
    else
        fout << superfunction(A, N, M, K);
    cout << superfunction(A, N, M, K) << endl;
    show(A, N, M);

    for (int i = 0; i < N; i++)
        delete[] A[i];
    delete[] A;
    return 0;
}
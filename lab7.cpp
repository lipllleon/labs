#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int A[11][11];
int N;

void getA(string fileName)
{
	ifstream fin(fileName);
	if (!fin.is_open()) {
		cout << "Файл " << fileName << " не открыт \n";
	}
	else {
		fin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				fin >> A[i][j];
		cout << "Матрица прочитана \n";
	}
}

void showA()
{
	cout << "\nМатрица A: \n";
	for (int i = 0; i < N; i++)
	{
		cout << " ";
		for (int j = 0; j < N; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void putA(string fileName)
{
	ofstream fout(fileName);
	if (!fout.is_open()) {
		cout << "Файл не открыт";
	}
	else {
		fout << N << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				fout << A[i][j] << " ";
			fout << "\n";
		}
		cout << "Матрица записана в " << fileName << endl;
	}
}

bool isSimilarMin() {
	int min = INT16_MAX;
	bool is = false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (A[i][j] < min) {
				min = A[i][j];
				is = false;
			}
			else if (A[i][j] == min)
				is = true;
		}
	return is;
}

bool isTwoEl() {
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (abs(A[i][j]) > 21)
				count++;
			if (count > 1)
				return 1;
		}
	return 0;
}

void sort() {
	for (int k = 0; k < N; k++)
		for (int j = 0; j < N - 1; j++)
			if (A[0][j] > A[0][j + 1])
				for (int i = 0; i < N; i++)
					swap(A[i][j], A[i][j + 1]);
	cout << "Матрица отсортирована \n";
}

int super(int a) {
	if (a < 0)
		return -1;
	else if (a == 0)
		return 0;
	else
		return 1;
}

int super(string s) {
	return s.length();
}

int main()
{
	setlocale(0, "");
	getA("input.txt");
	showA();
	if (isSimilarMin() && isTwoEl()) {
		sort();
	}
	showA();
	putA("output.txt");
	cout << "\n_________\n";
	cout << "\nsuper(2) = " << super(2);
	cout << "\nsuper(0) = " << super(0);
	cout << "\nsuper(-5) = " << super(-5);
	cout << "\nsuper(Привет) = " << super("Привет");
}
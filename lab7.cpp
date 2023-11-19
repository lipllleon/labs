#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int A[11][11];
int N;

//1 пункт
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

//2 пункт
int super(int a) {
	return (a > 0) - (a < 0);
}

int super(string s) {
	return s.length();
}

//1 доп
int fact(int a) {
	if (a < 0) {
		cout << "\nОшибка! Число не удовлетворяет условию (n >= 0)";
		return 0;
	}
	else if (a == 0)
		return 1;
	else
		return a * fact(a - 1);
}

//2 доп
void rec(int a, int b) {
	if (a == 1)
		return;
	if (a % b == 0) {
		cout << b << " ";
		rec(a / b, b);
	}
	else {
		rec(a, b + 1);
	}
}
void rec(int a) {
	cout << "\nРазложение на простые множители числа " << a << ": ";
	return rec(a, 2);
}

//4 доп
string astr(string s, int n) {
	for (int i = 0; i < n; i++) {
		if (!(s[i] == 'а')) {
			if (s[i] == 'ж')
				s[i] = 'ё';
			else if (s[i] == 'ё')
				s[i] = 'е';
			else 
				s[i] = (char)((int)s[i] - 1);
		}
	}
	return s;
}
string astr(string s) {
	return astr(s, s.length());
}
int numMax(string s, int n) {
	int max = -33;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if ((int)s[i] > max) {
			max = (int)s[i];
			maxi = i;
		}
	}
	return maxi;
}
string aaa(string s) {
	int l = s.length();
	int maxi = numMax(s, l);
	int count = 0;
	cout << "\n" << s;
	while (((int)s[maxi] > - 32) || (s[maxi] == 'ё')) {
		s = astr(s, l);
		count++;
		cout << " - " << s;
	}
	cout << "\nКол-во шагов: " << count << endl;
	return s;
}

//5 доп
string strokaPoNomeru(int a, int b) {
	string s = "";
	if (max(a, b) >= 0)
		for (int i = 0; i < max(a, b); i++)
			s += (char)min(a, b);
	return s;
}

int main()
{
	setlocale(0, "");

	cout << "\n1 пункт--------------------\n";
	getA("input.txt");
	showA();
	if (isSimilarMin() && isTwoEl()) {
		sort();
	}
	showA();
	putA("output.txt");

	cout << "\n2 пункт--------------------\n";
	cout << "\nsuper(2) = " << super(2);
	cout << "\nsuper(0) = " << super(0);
	cout << "\nsuper(-5) = " << super(-5);
	cout << "\nsuper(Привет) = " << super("Привет");

	cout << "\n\n1 доп--------------------\n";
	cout << "\nФакториал числа 6 = " << fact(6);
	cout << "\nФакториал числа 0 = " << fact(0);
	cout << "\nФакториал числа -5 = " << fact(-5);

	cout << "\n\n2 доп--------------------\n";
	rec(264);
	rec(15);
	rec(12342);

	cout << "\n\n3 доп--------------------\n";
	string a;
	a = aaa("абвгдеёжз");

	cout << "\n\n4 доп--------------------\n";
	cout << "strokaPoNomeru(40, -32) = " << strokaPoNomeru(40, -32);
}
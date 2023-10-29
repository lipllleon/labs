#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	short punkt, m, max, column, count;
	int n, k;
	bool sort;
	setlocale(0, "RU");
	cout << "Введите номер пункта: ";
	cin >> punkt;
	switch (punkt)
	{
	case 1:
		int a[20];
		sort = false;
		cout << "Введите кол-во элементов: ";
		cin >> k;
		cout << "Вводите элементы: ";
		for (int i = 0; i < k; i++) {
			cin >> a[i];
			n = a[i];
			while ((n / 10) > 0) {
				n /= 10;
			}
			if (n == 3) {
				sort = true;
			}
		}
		if (sort) {
			for (int i = 0; i < k - 1; i++) {
				for (int j = 0; j < k - i - 1; j++) {
					if (a[j] > a[j + 1]) {
						n = a[j];
						a[j] = a[j + 1];
						a[j + 1] = n;
					}
				}
			}
		}
		for (int i = 0; i < k; i++) {
			cout << a[i] << " ";
		}
		break;
	case 2:
		int t[20][20];
		max = 0;
		cout << "Введите кол-во строк: ";
		cin >> m;
		cout << "Введите кол-во стобцов: ";
		cin >> n;
		cout << "Введите элементы матрицы: ";
		for (int i = 0; i < m; i++) {
			cout << endl;
			for (int j = 0; j < n; j++) {
				cin >> t[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			count = 0;
			for (int j = 0; j < m; j++) {
				if (t[j][i] < 0) {
					count++;
				}
			}
			if (count > max) {
				max = count;
				column = i;
			}
		}
		for (int i = 0; i < m; i++) {
			t[i][column] = -1;
		}
		cout << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << t[i][j] << " ";
			}
			cout << endl;
		}
		break;
	default:
		break;
	}
}

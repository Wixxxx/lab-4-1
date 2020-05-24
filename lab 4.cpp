// lab 4.cpp : lab 4.1
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int maxElement(int array[], int size) {
	int max = size - 1;

	if (size == 1) {
		return array[max];
	}
	if (array[max] > array[max - 1] && array[max] % 2 == 0) {
		int temp = array[max];

		array[max] = array[max - 1];
		array[max - 1] = temp;
	}
	return maxElement(array, size - 1);
}



void Fill_Arr_Random(int * arr, int n, int min, int max) {
	srand(time(NULL));
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);


	for (int i = 0; i < n; i++)
		arr[i] = static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Print(int* arr, int n) {
	string s = ", ";
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
		{
			s = ".";
		}
		cout << arr[i] << s;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "");
	int size = 0;
	cout << "Введите размер массива: ";


	while (!(cin >> size) || size < 0) {
		cout << "\nОшибка! Введите целое положительное число: ";
		cin.clear();
		fflush(stdin);
	}

	int* array = new int[size];



	bool check = false;
	int j = 1;

	while (j != 2)
	{
		if (check) {
			cout << "Хотите еще попробовать?\n1 - Da \n2 - Нет\n>>";
			while (!(cin >> j) || j < 1 || j > 2) {
				cout << "\nОшибка! Введите 1 или 2: ";
				cin.clear();
				fflush(stdin);
			}
		}

		if (j == 2)
			break;

		Fill_Arr_Random(array, size, 0, 100);
		Print(array, size);
		cout << "Максимальный четный элемент = " << maxElement(array, size) << endl;
		cout << endl;
		check = true;
	}

	delete[]array;
	system("pause");

}
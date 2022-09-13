#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);

#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifndef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	delete[] arr;
#endif // !DYNAMIC_MEMORY_1

	int rows;	//количество строк двумерного динамического массива
	int cols;	//количество элементов строки
	cout << "Введите количество строк: ";				cin >> rows;
	cout << "Введите количество элементов строки: ";	cin >> cols;

	//1) Создаем массив указателей:
	int** arr = new int* [rows];
	//2) Выделяем память для строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	//3) Обращение к элементам двумерного динамического массива:
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	//4) Удаление массива:
	//4.1. Удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4.2. Удаляем массив указателей:
	delete[] arr;
}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* push_back(int* arr, int& n, int value)
{
	//1. Создаем буферный массив нужного размера, в данном случае на 1 элемент больше:
	int* buffer = new int[n + 1];
	//2. Копируем все данные из исходного массива в буферный:
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	//3. После того, как данные скопированы в новый массив, старый массив уже не нужен:
	delete[] arr;
	//4. Подменяем адрес старого массива адресом нового массива:
	arr = buffer;
	//5. Только после всего этого в новый элемент можно добавить значение:
	arr[n] = value;
	//6. После добавления элемента в массив, количество его элементов увеличится на 1:
	n++;
	//7. Mission complete - элемент добавлен
	return arr;
}

	
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS

	int a = 2;				
	int* pa = &a;			
	
	cout << a << endl;	
	cout << &a << endl;	
	cout << pa << endl;	
	cout << *pa << endl;

	int* pb;
	int b = 3;
	pb = &b;
	// (int) (int*)
		//int - int
		//int* - указатель на int
		//double - double
		//double* - указатель на double
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;

#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}


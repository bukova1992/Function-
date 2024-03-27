#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n, int minRand=0, int maxRand=100);
void Print(const int arr[], const int n);
int Sum(const int arr[], const int n);
double Avg(const int arr[], const int n);
int minValueln(const int arr[], const int n);
int maxValueln(const int arr[], const int n);
void shiftLeft(int arr[], const int n, int c);
void shiftRight(int arr[], const int n, int c);
void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	int minRand, maxRand;
	do
	{
		cout << "Введите минимальноe возможное случайное число:"; cin >> minRand;
		cout << "Введите максимальное возможное случайное число:"; cin >> maxRand;
		if (minRand == maxRand)cout << "Пределы диопазона не должны совпадать:" << endl;
	} while (minRand == maxRand);


#ifdef Fillrand
	int minRand, maxRand;
	do
	{
		cout << "Введите минимальное возможное случайное число:"; cin >> minRand;
		cout << "Введите максимально возможное случайное число:"; cin >> maxRand;
		if (minRand == maxRand)cout << "Пределы диопазона не должны совпадать" << endl;

	} while (minRand == maxRand);
#endif // Fillrand


	FillRand(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива:" << Sum(arr, n) << endl; 
	cout << "Среднее-арифметическое элементов массива:" << Avg(arr, n) << endl;
}   
void FillRand(int arr[], const int n, int minRand, int maxRand)

{
if (minRand < maxRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
minRand *= 100;
maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = minRand + rand() % (maxRand - minRand);
		arr[i] /= 100; 
	}
}
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
int Sum(const int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum; 
}
double Avg(const int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
int minValue(const int arr[], const int n)
{
	int maxValue;
	maxValue = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxValue)maxValue = arr[i];
	}
	return maxValue;

}

void shiftLeft(int arr[], const int n, int c)
{
	cout << "На сколько элементов сдвинуть массив: "; cin >> c;
	for (int i = 0; i < c; i++)
	{
		int buffer = arr[0];
		for (int j = 0; j < n - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[n - 1] = buffer;
	}
	Print(arr, n);

}
void shiftRight(int arr[], const int n, int c)
{
	cout << "На сколько элементов сдвинуть массив: "; cin >> c;
	for (int i = 0; i < c; i++)
	{
		int buffer = arr[n - 1];
		for (int j = n - 1; j > 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = buffer;
	}
	Print(arr, n);
}

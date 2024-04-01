#include<iostream>
using namespace std;
#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

const int ROWS = 3; // количество строк
const int COLS = 4; // количество элементов строки

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);

void Print(const int arr[], const int n);
void Print(const double arr[], const int n);
void Print(const int arr[ROWS][COLS], const int ROWS, const int COLS);
void Print(const double arr[ROWS][COLS], const int ROWS, const int COLS);

int Sum(const int arr[], const int n);
int Sum(const double arr[], const int n);
int Sum(const int arr[ROWS][COLS], const int ROWS, const int COLS);
int Sum(const double arr[ROWS][COLS], const int ROWS, const int COLS);

int Avg(const int arr[], const int n);
double Avg(const double arr[], const int n);

int minValueIn(const int arr[], const int n);
double minValueIn(const double arr[], const int n);
int minValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS);
double minValueIn(const double arr[ROWS][COLS], const int ROWS, const int COLS);

int maxValueIn(const int arr[], const int n);
double maxValueIn(const double arr[], const int n);
int maxValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS);
double maxValueIn(const double arr[ROWS][COLS], const int ROWS, const int COLS);

void shiftLeft(int arr[], const int n, int c);
void shiftLeft(double arr[], const int n, int c);



void shiftRight(int arr[], const int n, int c);
void shiftRight(double arr[], const int n, int c);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int i_arr[n];
	/*int minRand, maxRand;
	do
	{
		cout << "Введите минимально возможное случайное число: "; cin >> minRand;
		cout << "Введите максимально возможное случайное число: "; cin >> maxRand;
		if (minRand == maxRand)cout << "Пределы диапазона не должны совпадать: " << endl;
	} while (minRand == maxRand);*/

	FillRand(i_arr, n);
	Print(i_arr, n);
	cout << "Сумма элементов массива: " << Sum(i_arr, n) << endl;
	cout << "Среднее арифметическое элементов массива: " << Avg(i_arr, n) << endl;
	cout << "Минимальное значение массива: " << minValueIn(i_arr, n) << endl;
	cout << "Максимальное значение массива: " << maxValueIn(i_arr, n) << endl;
	int c = 0;
	shiftLeft(i_arr, n, c);
	shiftRight(i_arr, n, c);
	cout << delimiter << endl;

	const int D_SIZE = 8;
	double d_arr[D_SIZE];
	FillRand(d_arr, D_SIZE);
	Print(d_arr, D_SIZE);
	cout << "Сумма элементов массива: " << Sum(d_arr, D_SIZE) << endl;
	cout << "Минимальное значение массива: " << minValueIn(d_arr, n) << endl;
	cout << "Максимальное значение массива: " << maxValueIn(d_arr, n) << endl;
	int d = 0;
	shiftLeft(d_arr, n, d);
	shiftRight(d_arr, n, d);
	cout << delimiter << endl;

	int i_arr_2[ROWS][COLS];
	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << "Сумма элементов массива: " << Sum(i_arr_2, ROWS, COLS) << endl;
	cout << "Минимальное значение массива: " << minValueIn(i_arr_2, ROWS, COLS) << endl;
	cout << "Максимальное значение массива: " << maxValueIn(i_arr_2, ROWS, COLS) << endl;

	double i_arr_3[ROWS][COLS];
	FillRand(i_arr_3, ROWS, COLS);
	Print(i_arr_3, ROWS, COLS);
	cout << "Сумма элементов массива: " << Sum(i_arr_3, ROWS, COLS) << endl;
	cout << "Минимальное значение массива: " << minValueIn(i_arr_3, ROWS, COLS) << endl;
	cout << "Максимальное значение массива: " << maxValueIn(i_arr_3, ROWS, COLS) << endl;

}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	if (maxRand < minRand)
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
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	if (maxRand < minRand)
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
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	// заполнение двумерного массива случайными числами
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}
void Print(const double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}
void Print(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	// вывод двумерного массива на экран
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;

		}
		cout << endl;
	}
}
void Print(const double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;

		}
		cout << endl;
	}
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
int Sum(const double arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int Sum(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];

		}
	}
	return sum;
}
int Sum(const double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];

		}
	}
	return sum;
}
int Avg(const int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(const double arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
int minValueIn(const int arr[], const int n)
{
	int minValue;
	minValue = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < minValue)minValue = arr[i];
	}
	return minValue;
}
double minValueIn(const double arr[], const int n)
{
	double minValue;
	minValue = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < minValue)minValue = arr[i];

	}
	return minValue;
}
int maxValueIn(const int arr[], const int n)
{
	int maxValue;
	maxValue = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxValue)maxValue = arr[i];
	}
	return maxValue;

}
double maxValueIn(const double arr[], const int n)
{
	double maxValue;
	maxValue = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxValue)maxValue = arr[i];
	}
	return maxValue;

}
int minValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int minValue;
	minValue = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < minValue)minValue = arr[i][j];

		}
	}
	return minValue;
}
double minValueIn(const double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int minValue;
	minValue = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < minValue)minValue = arr[i][j];

		}
	}
	return minValue;
}
int maxValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int maxValue;
	maxValue = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > maxValue)maxValue = arr[i][j];

		}
	}
	return maxValue;
}
double maxValueIn(const double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int maxValue;
	maxValue = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > maxValue)maxValue = arr[i][j];

		}
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
void shiftLeft(double arr[], const int n, int d)
{
	cout << "На сколько элементов сдвинуть массив: "; cin >> d;
	for (int i = 0; i < d; i++)
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
void shiftRight(double arr[], const int n, int d)
{
	cout << "На сколько элементов сдвинуть массив: "; cin >> d;
	for (int i = 0; i < d; i++)
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


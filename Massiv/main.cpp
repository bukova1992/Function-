#include<iostream>
using namespace std; 

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"


const int ROWS = 3; // количество строк
const int COLS = 4; // количество элементов строки

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);

void Print(const int arr[], const int n);
void Print(const double arr[], const int n);
void Print(const int arr[ROWS][COLS], const int ROWS, const int COLS);

int Sum(const int arr[], const int n);
int Sum(const double arr[], const int n);
int Sum(const int arr[ROWS][COLS], const int ROWS, const int COLS);

double Avg(const int arr[], const int n);

int minValueIn(const int arr[], const int n);
double minValueIn(const double arr[], const int n);
int minValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS);

int maxValueIn(const int arr[], const int n);
double maxValueIn(const double arr[], const int n);
int maxValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS);

void shiftLeft(int arr[], const int n, int c);
void shiftLeft(double arr[], const int n, int c);
void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int c);


void shiftRight(int arr[], const int n, int c);
void shiftRight(double arr[], const int n, int c);

void Sort(int arr[], const int n);
void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS);
void Unique (int arr[ROWS][COLS], const int ROWS, const int COLS);

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
	Unique(i_arr_2, ROWS, COLS);
	cout << "Ввести случайное значение массива: " << maxValueIn(i_arr_2, ROWS, COLS) << endl;
	Sort(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	void Unique(int arr[ROWS][COLS], const int ROWS, const int COLS);
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
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(const double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
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
double Avg(const int arr[], const int n)
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
void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int c)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int k = 0; k < COLS; k++)
		{

		}
	}
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
void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++) //счётчик массива выбирает элемент массива 
	{
		int buffer = arr[i];
		for (int j = i + 1; j < n; j++) //счётчик массива перебивает оставшиеся элементы оставшиеся элементы массива 
		{
			//arr[i] //выбранный элемент 
			//arr[j] //перебираемый элемент 
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = j + 1; k < ROWS; k++)
			{
				//arr[i][j]-выбранный элемент
				//arr[i][k]-перебираемый элемент
				if (arr[i][k] < arr[i][j])
				{
					int buffer = arr[i][k];
					arr[i][j] = arr[i][k];
					arr[i][k] = buffer;
				}
			}
			for (int k = i; k < ROWS; k++)
			{
				for (int l = j + 1; l < COLS; l++)
				{
					//arr[i][j] - выбранный элемент
					//arr[k][l] - перебираемый элемент
					if (arr[i][j] < arr[k][l])
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = buffer;
					}
				}
			}
		}
	}
	void Unique(int arr[ROWS][COLS], const int ROWS, const int COLS)

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				bool unique;
				do
				{
					arr[i][j] = rand() % (ROWS * COLS);
					unique = true;
					for (int k = 0; k <= i; k++)
					{
						for (int 1 = 0; 1 < (k == i ? j : COLS); 1++)
						{
							if (arr[i][j] == arr[k][1])
							{
								unique = false;
								break;
							}
						}
						if (!unique)break;
					}
				} while (!unique);
			}
		}
}


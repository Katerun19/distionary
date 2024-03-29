#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Point
{
private:
	int x, y;
public:
	
	int c;
	void Set(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->c = x * x + y * y;
	}
	void Print()
	{
		cout << this->x << " " << this->y << endl;
		cout << this->c << endl;
	}
};

int main()  /*Выведите все исходные точки в порядке возрастания их расстояний от начала координат. 
			Входные данные
			Программа получает на вход набор точек на плоскости. Сначала задано количество точек n,
			затем идет последовательность из n строк, каждая из которых содержит два числа: координаты точки.
			Величина n не превосходит 100, все исходные координаты – целые числа, не превосходящие 103.
			Выходные данные
			Необходимо вывести все исходные точки в порядке возрастания их расстояний от начала координат.*/
{
	int n, x, y;
	cin >> n;
	
	Point *A = new Point[n];
	
	for (int i = 0; i < n; i++)//заполнение массива
	{
		cin >> x >> y;
		A[i].Set(x, y);
	}
	for (int j = 0; j < n; j++)//поиск минимума
	{
		int min = j;
		for (int i = j; i < n; i++)
		{
			if (A[min].c > A[i].c) { min = i; }
		}
		Point temp;
		temp = A[j];
		A[j] = A[min];
		A[min] = temp;
	}

	for (int i = 0; i < n; i++)//вывод массива
	{
		A[i].Print();
	}
	delete[] A;
	return 0;
}



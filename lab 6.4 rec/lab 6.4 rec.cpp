#include <iostream>
#include<iomanip>

using namespace std;

void Input(int* &a, const int size, int i)
{
	cout << "a[" << i << "] = ";
	cin >> a[i];

	if (i < size - 1)
		Input(a, size, i + 1);
	else
		cout << endl;
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int CountZero(int* a, const int size, int i)
{
	if (i == size)
		return 0;
	if (a[i] == 0)
		return CountZero(a, size, i + 1) + 1;
	return CountZero(a, size, i + 1);
}
int Min(int* a, const int size, int i, int min, int& imin)
{
	if (a[i] < min)
	{
		min = a[i];
		imin = i;
	}
	if (i < size - 1)
		return Min(a, size, i + 1, min, imin);
	else
		return min;
}
int Sum(int* a, const int size, int i)
{
	int imin = 0;
	int min = 0;
	if (i < size)
	{
		Min(a, size, i, min, imin);
		if (imin < i)
			return a[i] + Sum(a, size, i + 1);
		else
			return Sum(a, size, i + 1);
	}
	else
		return 0;
}
void Sort(int* a, const int size, int i)
{
	int min = a[i];
	int imin = i;
	for (int j=i+1; j<size; j++)
		if (min > a[j])
		{
			min = a[j];
			imin = j;
		}
	a[imin] = a[i];
	a[i] = min;

	if (i < size - 2)
		Sort(a, size, i + 1);
}
int main()
{
	int n;
	cout << "n = "; cin >> n;
	int* a = new int[n];

	Input(a, n, 0);
	Print(a, n, 0);

	cout << endl;
	cout << "Count Zero = " << CountZero(a, n, 0) << endl;
	cout << "Sum = " << Sum(a, n, 0) << endl;
	cout << endl;

	Sort(a, n, 0);
	Print(a, n, 0);
	
	delete[] a;
	return 0;
}
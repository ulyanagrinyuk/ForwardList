#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void elevator(int floor);
int Factorial(int n);
double Power(double a, int n);

void main()
{
	setlocale(LC_ALL, "");
	/*cout << "Hello World";
	main();*/
	int n;
	cout << "������� ����� �����: "; cin >> n;
	elevator(n);
}
void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "�� � �������" << endl;
		return;
	}
	cout << "�� �� " << floor << "�����\n";
	elevator(floor - 1);
	cout << "�� �� " << floor << "�����\n";
}
int Factorial(int n)
{
	if (n == 0)
	{
		return n;
	}
		return n * Factorial(n - 1);		
}
double Power(double a, int n)
{
	int i;
	double fractional = a;
	if (n == 0)
		fractional *= n;
	return fractional;
}


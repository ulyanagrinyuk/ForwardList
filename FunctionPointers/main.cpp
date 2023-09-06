#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void hello()
{
	cout << "Hello" << endl;
}
int sum(int a, int b)
{
	return a + b;
}

void main()
{
	void (*p_hello)() = hello;
	p_hello();

	/*cout << sum(2, 3) << endl;*/

	cout << sum << endl;
	int (*p_sum)(int, int) = sum;
	cout << p_sum(2, 3) << endl;

}
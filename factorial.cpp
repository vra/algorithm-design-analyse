#include <iostream>

int factorial(int n)
{
	//border condition 
	if (n == 0)
	{
		return 1;
	}

	//recursion 
	return n * factorial(n - 1);
}

int main()
{
	int a = factorial(11);
	return 0;
}
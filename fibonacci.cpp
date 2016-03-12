#include <iostream>

int fibonacci(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Fibonacci of " << i << " is " << fibonacci(i) << std::endl;
	}

	return 0;
}
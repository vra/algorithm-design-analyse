#include <iostream>

int integerSplit(int n, int m)
{
	if (m == 1)
	{
		return 1;
	}

	if (n < m)
	{
		return integerSplit(n, n);
	}

	if (n == m)
	{
		return 1 + integerSplit(n, n - 1);
	}

	if (n > m && m > 1)
	{
		return integerSplit(n, m - 1) + integerSplit( n - m, m);
	}
}


int main()
{
	int n = integerSplit(6,6);

	return 0;
}
#include <iostream>

int ackerman(int n, int m)
{
	if (n == 0)
	{
		return 1;
	}

	if (n == 1 && m == 0)
	{
		return 2;
	}

	if (n >= 2 && m == 0)
	{
		return n+2;
	}

	if (n >=1 && m >= 1)
	{
		return ackerman(ackerman(n - 1, m), m - 1);
	}
}


int main()
{
	//stack will be over flow 
	int a = ackerman(4,3);

	return 0;
}
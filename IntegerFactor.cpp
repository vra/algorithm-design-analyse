#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
*/
void integerFactor(int integer, int& numOfFactor)
{
	if (integer == 2)
	{

	}

	int sqrtOfInteger = int(sqrt(integer));
	for (int i = 2; i <= sqrtOfInteger; i++)
	{
		if (integer % i == 0 && integer / 2 <= sqrtOfInteger)
		{

		}
	}
}

int total = 0;
void solve(long n)
{
	if (n == 1)
	{
		total ++;
	}
	else
	{
		for (long i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				solve(n / i);
			}
		}
	}
}


int main()
{
	int integer = 0;
	int numOfFactor = 1;

	//read data from input file.
	ifstream in("input.txt");
	if (!in.is_open())
	{
		cout << "ERROR: open input file failed" << endl;
		return -1;
	}
	in >> integer;
	in.close();

//	integerFactor(integer, numOfFactor);
	solve(20000000009);
	int a = total;
	
	//write result to output file.
	ofstream out("output.txt");
	if (!out.is_open())
	{
		cout << "ERROR: open output file failed" << endl;
		return -1;
	}

	out << numOfFactor;
	out.close();

	return 0;
	
}
#include <iostream>
#include <vector>

using namespace std;

//NOTE: v has been sorted.
template<class T>
int binarySearch(vector<T> v, const T& x, int left, int right)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (v[middle] == x)
		{
			return middle;
		}

		if (v[middle] > x)	//search the left part
		{
			right = middle - 1;
		}
		else               //search the right part
		{
			left = middle + 1;
		}
	}

	//not found x in sequence.
	return -1;
}

//Use recursive algorithm to implement binary search.
template<class T>
int binarySearchRecursion(vector<T> v, const T& x, int left, int right)
{
	if (left > right)
	{
		return -1;
	}

	int middle = (left + right) / 2;

	if (v[middle] == x)
	{
		return middle;
	}

	if (v[middle] > x)
	{
		right = middle - 1;
		return binarySearch(v, x, left, right);
	}
	else 
	{
		left = middle + 1;
		return binarySearch(v, x, left, right);
	}
}

int main()
{
	vector<float> a = vector<float>();
	a.push_back(2.1);
	a.push_back(6.1);
	a.push_back(9.1);
	a.push_back(13.1);
	a.push_back(19.1);
	a.push_back(82.1);

	int k = binarySearchRecursion(a, 1.1f, 0, a.size() - 1);

	return 0;
}




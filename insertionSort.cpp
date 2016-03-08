#include <vector>
#include <iostream>

using namespace std;

// Use vector to implement function for int input 
vector<int> insertionSort(vector<int> v)
{
	for(int j = 1; j < v.size(); j++)
	{
		int key = v[j];
		int i = j - 1;
		//centrel idea£º for every value, compares with values ahead it, if the value is bigger than it, 
		//than move that value to next position, do this process until the value is not bigger than it.
		while (i > -1 && v[i] > key)
		{
			v[i + 1] = v[i];
			i = i - 1;
		}

		v[i + 1] = key;
	}

	return v;
}

// C-style code
int* insertionSort(int A[], int length)
{
	for(int j = 1; j < length; j++)
	{
		int key = A[j];	
		int i = j - 1;
		while (i > -1 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}

		A[i + 1] = key;
	}

	return A;
}

//Template implement. T can be any type that's comparable.
template<class T>
vector<T> insertionSort(vector<T> V)
{
	for (int j = 1; j < V.size(); j++)
	{
		T key = V[j];
		int i = j - 1;

		while (i > -1 && V[i] > key)
		{
			V[i + 1] = V[i];
			i = i - 1;
		}

		V[i + 1] = key;
	}

	return V;
}

int main()
{
	vector<int> v = vector<int>();
	v.push_back(8);
	v.push_back(2);
	v.push_back(4);
	v.push_back(9);
	v.push_back(3);
	v.push_back(6);

	v = insertionSort(v);
	int A[] = {8,2,4,9,3,6};
	int* pA = insertionSort(A, 6);

	vector<char> fv = vector<char>();
	fv.push_back('d');
	fv.push_back('a');
	fv = insertionSort(fv);

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

//Merge two ordered lists.
template<class T>
vector<T> Merge2List(vector<T> V1, vector<T> V2)
{
	vector<T> V3 = vector<T>();

	int i = 0;
	int j = 0;
	int k = 0;


	while (i < V1.size() && j < V2.size())
	{
		if (V1[i] < V2[j])
		{
			V3.push_back(V1[i]);
			i++;
			k++;
		}
		else 
		{
			V3.push_back(V2[j]);
			j++;
			k++;
		}
	}

	//V1 has some part left.
	if (i < V1.size())
	{
		V3.insert(V3.end(), V1.begin() + i, V1.end());
	}
	//V2 has some part left.
	else if (j < V2.size())
	{
		V3.insert(V3.end(), V2.begin() + j, V2.end());
	}


	return V3;
}

//Implement of merging sort.
template<class T>
vector<T> MergeSort(vector<T> V)
{
	if (V.size() == 1)
	{
		return V;
	}
	vector<T> p1 = vector<T>();
	vector<T> p2 = vector<T>();
	//NOTE: the position in last parameter is not included.
	p1.insert(p1.end(), V.begin(), V.begin() + int(V.size()/2));
	p2.insert(p2.end(), V.begin()+ int(V.size()/2), V.end());
	p1 = MergeSort(p1);
	p2 = MergeSort(p2);

	return Merge2List(p1, p2);
}

int main()
{
	vector<int> v1 = vector<int>();
	v1.push_back(9);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(23);
	v1.push_back(13);
	v1.push_back(4);


	vector<int> v3 = MergeSort(v1);

	return 0;
}


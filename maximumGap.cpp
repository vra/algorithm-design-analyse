#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

/*
	function to find the max gap in some real value numbers.
	* in 'input.txt' file ,first line is the number of real values
	* second line list these real values.
	* in 'output.txt', list the max margin.
*/
void maxmimumGap()
{

	int length = 0;
	float tmp = 0.0f;
	float maxMargin  = 0.0f;
	vector<float> realValues = vector<float>();

	/*0. read data from input file.*/
	ifstream fin("input.txt");
	if (!fin.is_open())
	{
		cout << "open input.txt failed.\n";
		return;
	}

	fin >> length;
	while(fin >> tmp)
	{
		realValues.push_back(tmp);
	}
	fin.close();

		
	/*1. find minimum and maximum*/
	int numOfValues = realValues.size();
	float min = realValues[0];
	float max = realValues[0];
	for (int i = 1; i < numOfValues; i++)
	{
		if (realValues[i] < min)
		{
			min = realValues[i];
		}
		if (realValues[i] > max)
		{
			max = realValues[i];
		}
	}

	/*2. split range max - min to (n - 1) parts averagely.*/
	float avgMargin = (max - min) / (numOfValues - 1);

	/*3 use vector of float vectors to store real values in format of bucket*/
	vector<vector<float> > buckets = vector<vector<float> >(numOfValues);

	for (int i = 0; i < numOfValues; i++)
	{
		//construct [ ) space, put each value input a bucket.
		int idOfBucket = int( (realValues[i] -min) / avgMargin);
		buckets[idOfBucket].push_back(realValues[i]);
	}

	/*4 get the max gap in successive (not empty) buckets*/
	float prevMax = *max_element(buckets[0].begin(), buckets[0].end()); //get max element in a vector.
	float maxGap = 0.0f;
	for (int i = 1; i < numOfValues; i++)
	{
		if (buckets[i].empty())
		{
			continue;
		}
		
		float currMax = *max_element(buckets[i].begin(), buckets[i].end());
		float currGap = currMax - prevMax;
		if (maxGap < currGap) 
		{
			maxGap = currGap;
		}
		prevMax = currMax;
	}


	/*5 write result to output file */
	ofstream fout("output.txt");
	fout << maxGap;
	fout.close();
}

int main()
{
	maxmimumGap();
	return 0;
}
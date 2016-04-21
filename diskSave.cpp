#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

float diskSave(vector<int> retrievalRate)
{
	//Use to save float type of rates
	vector<float> orderedRate(retrievalRate.size());

	
	//Sort the rates first
	sort(retrievalRate.begin(), retrievalRate.end());

	//Get the sum of rates so we can use it to get float rates later
	int sumOfRate = 0;
	for (int r : retrievalRate)
	{
		sumOfRate += r;
	}

	//Arrange the order of rates, Maximum in middle, smaller in the two sides
	for(int i = 0; i < retrievalRate.size() / 2; ++i)
	{
		orderedRate[i] = float(retrievalRate[2*i]) / sumOfRate;
		orderedRate[retrievalRate.size() - i - 1] = float(retrievalRate[2*i+1]) / sumOfRate;
	}

	// Fill the center one if we have odd numbers
	if (retrievalRate.size() % 2 == 1)
	{
		orderedRate[retrievalRate.size() / 2] = float(retrievalRate[retrievalRate.size() - 1]) / sumOfRate;
	}

	//Calculate the shortest time
	double shortestTime = 0;
	for (int i = 0; i < retrievalRate.size() - 1; ++i)
	{
		for (int j = i+1; j < retrievalRate.size(); ++j)
		{
			shortestTime += (j - i) * orderedRate[i] * orderedRate[j];
		}
	}

	return shortestTime;
}

int main()
{
	ifstream in("input.txt");
	if (!in.is_open())
	{
		cout << "ERROR: can't open input.txt" << endl;
		return -1;
	}
	int num = 0;
	in >> num;
	vector<int> retrievalRate;
	int currRate = 0;
	while (in>> currRate)
	{
		retrievalRate.push_back(currRate);
	}
	in.close();

	float result = diskSave(retrievalRate);

	ofstream out("output.txt");
	if (!out.is_open())
	{
		cout << "ERROR: can't open output.txt" << endl;
		return -1;
	}
	out << result;
	out.close();

	return 0;
}
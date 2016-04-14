#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

int editDistance(string A, string B)
{
	if (A == B)
	{
		return 0;
	}

	int lenOfA = A.size();
	int lenOfB = B.size();

	//Initalize matrix saving distance
	vector<vector<int>> distance(lenOfA+1, vector<int>(lenOfB+1, 0));

	for (int i = 0; i < lenOfA+1; ++i)
	{
		distance[i][0] = i;
	}

	for (int i = 0; i < lenOfB+1; ++i)
	{
		distance[0][i] = i;
	}

	for (int i = 1; i < lenOfA+1; ++i)
	{
		for (int j = 1; j < lenOfB+1; ++j)
		{
			int cost = A[i] == B[j] ? 0 : 1;
			int deletion = distance[i - 1][j] + 1;
			int insertion = distance[i][j - 1] + 1; 
			int replaciation = distance[i - 1][j - 1] + cost;
			distance[i][j] = min(min(deletion, insertion), replaciation);
		}
	}

	return distance[lenOfA][lenOfB];
} 

int main()
{
	string inputFile = "input.txt";
	string outputFile = "output.txt";

	//Read input.txt
	ifstream in(inputFile);
	if (!in.is_open())
	{
		cout << "ERROR: Open input file failed. exit";
		return -1;
	}

	string A;
	string B;
	getline(in, A);	
	getline(in, B);	
	in.close();

	//Calculate the edit distance
	int distance = editDistance(A,B);

	//Output result
	ofstream out(outputFile);
	if (!out.is_open())
	{
		cout << "ERROR: Open out file failed. exit";
		return -1;
	}
	out << distance;
	out.close();

	
	cout << "A:" << A << endl;
	cout << "B:" << B << endl;
	cout << "distance:" << distance << endl;

	return 0;
}
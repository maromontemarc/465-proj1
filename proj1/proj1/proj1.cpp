// Programming project 1
// Marc Maromonte

#include "pch.h"
#include <iostream>
#include <stack>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
	// Opens the lab1in.txt file
	//
	ifstream inFile;
	inFile.open("lab1in.txt");

	// If unable to open file exit
	//
	if (!inFile)
	{
		cout << "Unable to open file";
		exit(1);
	}

	int n = -1;
	bool end = false;

	// Checks cases until end of file
	//
	while (!end && !inFile.eof())
	{
		stack <int> stack;
		int a[1000];
		int b[1000];
		int testCase[1000];
		int temp;
		bool nextBlock = false;

		inFile >> temp;
		
		// Checks if 0 occurs once or twice
		//
		if (temp == 0)
		{
			inFile >> temp;
			
			if (temp == 0)
			{
				end = true;
				break;
			}
			else
			{
				n = temp;
				
				for (int i = 0; i < n; i++)
				{
					inFile >> testCase[i];
					a[i] = testCase[i];
				}
			}
		}
		else if (n == -1)
		{
			n = temp;
			for (int i = 0; i < n; i++)
			{
				inFile >> testCase[i];
				a[i] = testCase[i];
			}
		}
		else
		{
			testCase[0] = temp;
			a[0] = temp;

			for (int j = 1; j < n; j++)
			{
				inFile >> testCase[j];
				a[j] = testCase[j];
			}
		}

		// Sorts the A track
		//
		sort(a, a + n);

		int aIndex = 0;
		int bIndex = 0;
		int tIndex = 0;
		bool output = false;

		// Checks if the case is possible
		//
		while (bIndex < n && tIndex < n && aIndex < n)
		{
			while (!stack.empty() && stack.top() == testCase[tIndex])
			{
				b[bIndex] = stack.top();
				stack.pop();
				bIndex++;
				tIndex++;
			}

			if (a[aIndex] != testCase[tIndex])
			{
				stack.push(a[aIndex]);
				aIndex++;
			}
			else if (a[aIndex] == testCase[tIndex])
			{
				stack.push(a[aIndex]);
				b[bIndex] = stack.top();
				stack.pop();
				aIndex++;
				bIndex++;
				tIndex++;
			}
			
			while (aIndex == n && !stack.empty())
			{
				b[bIndex] = stack.top();
				stack.pop();
				bIndex++;
				tIndex++;
			}
		}

		// Checks if B track and the test case are equal
		//
		for (int i = 0; i < n; i++)
		{
			if (b[i] == testCase[i])
			{
				output = true;
			}
			else
			{
				output = false;
			}
		}

		// Displays Yes if possible and No if not possible
		//
		if (output == true)
		{
			cout << "Yes \n";
		}
		else
		{
			cout << "No \n";
		}
	} 

	// Closes lab1in.txt
	//
	inFile.close();

	return 0;
}


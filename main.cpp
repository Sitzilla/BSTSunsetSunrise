#include <iostream>
#include <fstream>
#include <string>

#include "tree.h"
#include "day.h"
using namespace std;

void doit(istream &fin)
{
	BinaryTree sunriseTree;
	BinaryTree sunsetTree;

	int year, month, day, sunrise, sunset;
	while(true)
	{
		fin >> year >> month >> day >> sunrise >> sunset;
		if(fin.eof())
		{
			break;
		}
		Day tempDate(year, month, day, sunrise, sunset);

		sunriseTree.insert(sunrise, tempDate.getDate());
		sunriseTree.insert(sunset, tempDate.getDate());
	}

	// todo: use the binary tree here
}

void ignoreLines(istream &fin, int n)
{
	for(int i = 0; i < n; i++)
	{
		fin.ignore(255, '\n');
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "Please enter a filename!\n";
		return 1;
	}

	ifstream fin("sunrise-sunset.txt");
	if(fin.fail())
	{
		cout << "Error reading file!\n";
		return 1;
	}

	ignoreLines(fin, 3);
	doit(fin);
	fin.close();

	return 0;
}

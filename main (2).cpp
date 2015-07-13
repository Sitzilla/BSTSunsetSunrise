#include <iostream>
#include <fstream>
using namespace std;

void doit(istream &fin)
{
	// todo: set up binary tree here

	int year, month, date, sunrise, sunset;
	while(true)
	{
		fin >> year >> month >> date >> sunrise >> sunset;
		if(fin.eof())
		{
			break;
		}

		// todo: insert dates into binary tree here

		// uncomment the code below to verify
		// that you are loading the file correctly
		/*
		cout << year << "-"
		     << month << "-"
		     << date << " "
		     << sunrise << " "
		     << sunset << endl;
		*/
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

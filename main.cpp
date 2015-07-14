#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "tree.h"
#include "day.h"
#include "tokenizer.h"

using namespace std;

void parseInput(string input, BinaryTree sunriseTree, BinaryTree sunsetTree) {
	Tokenizer tokenizer;
	string token;

	tokenizer.tokenize(input);
	tokenizer.nextToken(token);

	if (token == "sunrise") {
		tokenizer.nextToken(token);
		if (token == "before") {
			tokenizer.nextToken(token);
			int before;
			(stringstream(token) >> before) ? cout << "Sunrise before: " << before << endl : cerr << "Incorrect Input" << endl;
			sunriseTree.printBefore(before);
		}
		if (token == "after") {
			tokenizer.nextToken(token);
			int after;
			(stringstream(token) >> after) ? cout << "Sunrise after: " << after << endl : cerr << "Incorrect Input" << endl;
			sunriseTree.printAfter(after);
		}
		if (token == "between") {
			tokenizer.nextToken(token);
			int after;
			(stringstream(token) >> after) ? cout << "Sunrise after: " << after << endl : cerr << "Incorrect Input" << endl;
			tokenizer.nextToken(token);
			int before;
			(stringstream(token) >> before) ? cout << "And before: " << before << endl : cerr << "Incorrect Input" << endl;
			sunriseTree.printBetween(after, before);
		}

	} else if (token == "sunset") {
		tokenizer.nextToken(token);
		if (token == "before") {
			tokenizer.nextToken(token);
			int before;
			(stringstream(token) >> before) ? cout << "Sunset before: " << before << endl : cerr << "Incorrect Input" << endl;
			sunsetTree.printBefore(before);
		}
		if (token == "after") {
			tokenizer.nextToken(token);
			int after;
			(stringstream(token) >> after) ? cout << "Sunset before: " << after << endl : cerr << "Incorrect Input" << endl;
			sunsetTree.printAfter(after);
		}
		if (token == "between") {
			tokenizer.nextToken(token);
			int after;
			(stringstream(token) >> after) ? cout << "Sunset after: " << after << endl : cerr << "Incorrect Input" << endl;
			tokenizer.nextToken(token);
			int before;
			(stringstream(token) >> before) ? cout << "And before: " << before << endl : cerr << "Incorrect Input" << endl;
			sunsetTree.printBetween(after, before);
		}
	}
}


void doit(istream &fin)
{
	string quitCommand = "quit";
	string printCommand = "all";

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

		sunriseTree.insert(sunrise, tempDate);
		sunsetTree.insert(sunset, tempDate);
	}

	cout << "Welcome to the Sunrise/Sunset tool!" << endl;
	cout << "Enter one of the following commands:" << endl;
    cout << "(sunrise|sunset) before [time]" << endl;
    cout << "(sunrise|sunset) after [time]" << endl;
    cout << "(sunrise|sunset) between [start_time] [end_time]" << endl;
    cout << "all" << endl;
    cout << "quit" << endl;
    
    while (true) {
    	string input;

	    cout << "Enter calculation..." << endl;
        getline(cin, input);


        if(input == printCommand) {
            cout << "Current variables assigned:" << endl;
            sunriseTree.print();
        }
        else if(input == quitCommand) {
            exit(0);                  
        }
        else {
        	parseInput(input, sunriseTree, sunsetTree);

        }
    }
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

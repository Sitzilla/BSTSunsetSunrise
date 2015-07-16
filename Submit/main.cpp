#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "tree.h"
#include "day.h"
#include "tokenizer.h"

using namespace std;

// Checks that a string token is only either 3 or 4 characters long and could be converted into an
// integer representation of military time (ex '1859' would return true but '1860' would return false)
bool legalToken(string input) {

	if ((input.length() > 4) || (input.length() < 3)) {
		cout << "Incorrect Time... needs to be in military time" << endl;
		return false;
	}

	if (input.length() == 3) {
		int indexedChar = static_cast<int>(input[1]);
		if (indexedChar < 48 || indexedChar > 53) {
			cout << "Incorrect Time... needs to be in military time" << endl;
			return false;
		}
	}

	if (input.length() == 4) {
		int indexedChar = static_cast<int>(input[2]);
		if (indexedChar < 48 || indexedChar > 53) {
			cout << "Incorrect Time... needs to be in military time" << endl;
			return false;
		}
	}
	return true;
}

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
			(stringstream(token) >> before) ? cout << "Sunrise before: " << before << endl : cerr << endl;
			if (legalToken(token)) {
				sunriseTree.printBefore(before);
			}
		} else if (token == "after") {
			tokenizer.nextToken(token);
			int after;
			(stringstream(token) >> after) ? cout << "Sunrise after: " << after << endl : cerr << endl;
			if (legalToken(token)) {
				sunriseTree.printAfter(after);
			}
		} else if (token == "between") {
			tokenizer.nextToken(token);
			int after;
			(stringstream(token) >> after) ? cout << "Sunrise after: " << after << endl : cerr << endl;
			if (legalToken(token)) {
				tokenizer.nextToken(token);
				int before;
				(stringstream(token) >> before) ? cout << "And before: " << before << endl : cerr << endl;
				if (legalToken(token)) {
					sunriseTree.printBetween(after, before);
				}
			}
		} else {
			cout << "Incorrect parameters input! Type 'before', 'after', or 'between'" << endl;
		}

	} else if (token == "sunset") {
		tokenizer.nextToken(token);
		if (token == "before") {
			tokenizer.nextToken(token);
			int before;
			(stringstream(token) >> before) ? cout << "Sunset before: " << before << endl : cerr << endl;
			if (legalToken(token)) {
				sunsetTree.printBefore(before);
			}
		} else if (token == "after") {
			tokenizer.nextToken(token);
			int after;
			(stringstream(token) >> after) ? cout << "Sunset after: " << after << endl : cerr << endl;
			if (legalToken(token)) {
				sunsetTree.printAfter(after);
			}
		} else if (token == "between") {
			tokenizer.nextToken(token);
			int after;
			(stringstream(token) >> after) ? cout << "Sunset after: " << after << endl : cerr << endl;
			if (legalToken(token)) {
				tokenizer.nextToken(token);
				int before;
				(stringstream(token) >> before) ? cout << "And before: " << before << endl : cerr << endl;
				if (legalToken(token)) {
					sunsetTree.printBetween(after, before);
				}
			}
		} else {
			cout << "Incorrect parameters input! Type 'before', 'after', or 'between'" << endl;
		}
	} else {
		cout << "Incorrect command was input! Type either 'sunrise' or 'sunset'" << endl;
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

	    cout << "Enter time..." << endl;
        getline(cin, input);


        if(input == printCommand) {
            cout << "Current variables assigned:" << endl;
            sunriseTree.print();
        }
        else if(input == quitCommand) {
        	cout << "Goodbye!" << endl;
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

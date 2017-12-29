// BusTimetable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include "Bus.h"
#include "Timetable.h"

using namespace std;


int main()
{
	bool exitFlag = false;
	Timetable timetable("test.txt");
	
	std::map <std::string, int>commandMapping;

	commandMapping["add"] = 1;
	commandMapping["del"] = 2;
	commandMapping["getall"] = 3;
	commandMapping["edit"] = 4;
	commandMapping["find"] = 5;
	commandMapping["q"] = 6;

	while (!exitFlag) {
		string commandString;
		cin >> commandString;

		string command;
		string substring;
		std::stringstream commandStringsream(commandString);
		std::vector<string> params;
		int i = 0;
		while (getline(commandStringsream, substring, '-')) {
			if (i > 0) {
				params.push_back(substring);
			}
			else {
				command = substring;
			}			
			i++;
		}

		HandleCommand(commandMapping[command], params, timetable, exitFlag);
	}

	
    return 0;
}

void HandleCommand(int commandNumber, std::vector<string> params, Timetable timetable, bool exitFlag)
{
	switch (commandNumber)
	{
	case 1:
		capa++;
		break;
	case 2:
		lettera++;
		break;
	case 3:
		capa++;
		break;
	case 4:
		lettera++;
		break;
	case 5:
		capa++;
		break;
	case 6:
		exitFlag = true;
		break;
	default:
		nota++;
	}
}


// BusTimetable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include "Bus.h"
#include "BusBuilder.h"
#include "Timetable.h"

using namespace std;

void HandleCommand(int commandNumber, std::vector<string> params, Timetable* timetable)
{
	const string commonParamsErrorText = "Wrong params list.";
	const string commonErrorText = "Unable to process the command. Please check the arguments list and try again;";
	switch (commandNumber)
	{
	case 1:
	{
		try {
			if (params.size() < 5) {
				cout << commonParamsErrorText << endl;
			}
			Bus newBus = BusBuilder::BuildBus(params);
			timetable->AddRecord(newBus);
		}
		catch (exception) {
			cout << commonErrorText << endl;
		}
	}
	break;
	case 2:
	{
		try {
			if (params.size() < 1) {
				cout << commonParamsErrorText << endl;
			}
			timetable->DeleteRecord(stoi(params[0]));
		}
		catch (exception) {
			cout << commonErrorText << endl;
		}
	}
		break;
	case 3:
	{
		try {			
			std::vector<Bus> buses = timetable->GetRecords();
			for (unsigned int counter = 0; counter < buses.size(); counter++) {
				cout << buses[counter].ToString() << endl;
			}
		}
		catch (exception) {
			cout << commonErrorText << endl;
		}
	}
		break;
	case 4:
	{
		try {
			if (params.size() < 5) {
				cout << commonParamsErrorText << endl;
			}
			Bus newBus = BusBuilder::BuildBus(params);
			timetable->UpdateRecord(newBus);
			
		}
		catch (exception) {
			cout << commonErrorText << endl;
		}
	}
		break;
	case 5:
	{
		try {
			tm time = BusBuilder::parseTimeString(params[1]);
			std::vector<Bus> buses = timetable->FindSuitableBuses(params[0], time);

			for (unsigned int counter = 0; counter < buses.size(); counter++) {
				cout << buses[counter].ToString() << endl;
			}
		}
		catch (exception) {
			cout << commonErrorText << endl;
		}
	}
		break;
	case 0:
		exit(0);
		break;
	default:
		break;
	}
}


int main()
{
	Timetable* timetable = new Timetable("test.txt");
	
	std::map <std::string, int>commandMapping;

	commandMapping["q"] = 0;
	commandMapping["add"] = 1;
	commandMapping["del"] = 2;
	commandMapping["getall"] = 3;
	commandMapping["edit"] = 4;
	commandMapping["find"] = 5;
	
	cout << "The timetable is ready." << endl;

	while (true) {
		cout << "Please, enter your command" << endl;
		string commandString;
		getline(cin, commandString);
		
		string command;
		string substring;
		std::stringstream commandStringsream(commandString);
		std::vector<string> params;
		int i = 0;
		while (getline(commandStringsream, substring, ' ')) {
			if (i > 0) {
				params.push_back(substring);
			}
			else {
				command = substring;
			}			
			i++;
		}

		int commandNumber = commandMapping[command];
		HandleCommand(commandNumber, params, timetable);
	}

    return 0;
}



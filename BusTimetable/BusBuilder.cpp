#include "stdafx.h"
#include "BusBuilder.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Bus BusBuilder::BuildBus(std::vector<string> busFields)
{
	if (busFields.size() == 6)
	{
		tm departureTime = BusBuilder::parseTimeString(busFields[4]);
		tm arrivalTime = BusBuilder::parseTimeString(busFields[5]);

		Bus bus(stoi(busFields[0]), stoi(busFields[1]), busFields[2], busFields[3], departureTime, arrivalTime);
		return bus;
	}
	else if(busFields.size() == 5)
	{
		tm departureTime = BusBuilder::parseTimeString(busFields[3]);
		tm arrivalTime = BusBuilder::parseTimeString(busFields[4]);

		Bus bus(stoi(busFields[0]), busFields[1], busFields[2], departureTime, arrivalTime);

		return bus;
	}
	
	return Bus();
}

tm BusBuilder::parseTimeString(string timeString)
{
	tm time;
	std::stringstream timeStringStream(timeString);
	string hours;
	string minutes;
	getline(timeStringStream, hours, ':');
	getline(timeStringStream, minutes);
	time.tm_hour = stoi(hours);
	time.tm_min = stoi(minutes);

	return time;
}

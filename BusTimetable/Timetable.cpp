#include "stdafx.h"
#include "Timetable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Timetable::Timetable(std::string fileName)
{
	_fileName = fileName;
	this->GetData();
}

void Timetable::GetData()
{
	string line;
	string text;
	int counter = 0;
	ifstream myfile(_fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//cout << line << endl;
			text = text + line + ";";
			counter++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	//static Bus * timetableData = new Bus[counter];
	std::vector<Bus> timetableData;
	counter = 0;


	std::stringstream fullData(text);
	while (getline(fullData, line, ';')) {
		string subString;
		std::stringstream busStringfullData(line);
		string* busFields = new string[6];
		int i = 0;
		while (getline(busStringfullData, subString, ',')) {
			busFields[i] = subString;
			i++;
		}
		tm departureTime;
		std::stringstream timeString(busFields[4]);
		string hours;
		string minutes;
		getline(timeString, hours, ':');
		getline(timeString, minutes);
		departureTime.tm_hour = stoi(hours);
		departureTime.tm_min = stoi(minutes);

		tm arrivalTime;
		std::stringstream timeString2(busFields[5]);
		string hours2;
		string minutes2;
		getline(timeString2, hours, ':');
		getline(timeString2, minutes);
		arrivalTime.tm_hour = stoi(hours);
		arrivalTime.tm_min = stoi(minutes);

		Bus bus(stoi(busFields[0]), stoi(busFields[1]), busFields[2], busFields[3], departureTime, arrivalTime);
		Timetable::_buses.push_back(bus);
	}
}

void Timetable::AddRecord(Bus bus)
{
	if (!_buses.empty()) {
		Bus lastBus = _buses.back();
		int lastBusId = lastBus.GetId();
		bus.SetId(lastBusId + 1);
	}
	else {
		bus.SetId(1);
	}

	_buses.push_back(bus);

	std::ofstream out;
	out.open(_fileName, std::ios::app);
	out << bus.ToString() << endl;
	out.close();
}

void Timetable::DeleteRecord(int busId)
{
	vector<Bus> updatedBusesList;
	std::ofstream ofs;
	ofs.open(_fileName, std::ofstream::out | std::ofstream::trunc);
	for (int counter = 0; counter < _buses.size(); counter++) {
		if (_buses[counter].GetId() != busId) {
			updatedBusesList.push_back(_buses[counter]);
			ofs << _buses[counter].ToString() << endl;
		}		
	}
	ofs.close();
	_buses.swap(updatedBusesList);
}

void Timetable::UpdateRecord(Bus updatedBus)
{
	vector<Bus> updatedBusesList;
	std::ofstream ofs;
	ofs.open(_fileName, std::ofstream::out | std::ofstream::trunc);
	for (int counter = 0; counter < _buses.size(); counter++) {
		if (_buses[counter].GetId() != updatedBus.GetId()) {
			updatedBusesList.push_back(_buses[counter]);
			ofs << _buses[counter].ToString() << endl;
		}
		else {
			updatedBusesList.push_back(updatedBus);
			ofs << updatedBus.ToString() << endl;
		}		
	}
	ofs.close();
	_buses.swap(updatedBusesList);
}

std::vector<Bus> Timetable::GetRecords()
{
	return _buses;
}

std::vector<Bus> Timetable::FindSuitableBuses(tm arrivalTime)
{
	vector<Bus> filteredBusesList;

	for (int counter = 0; counter < _buses.size(); counter++) {
		tm time = _buses[counter].GetArrivalTime();
		if (time.tm_hour <= arrivalTime.tm_hour && time.tm_min <= arrivalTime.tm_min) {
			filteredBusesList.push_back(_buses[counter]);
		}
	}

	return std::vector<Bus>();
}

Timetable::~Timetable()
{
}

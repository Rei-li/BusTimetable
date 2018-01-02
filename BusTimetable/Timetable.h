#include <string>
#include <vector>
#include "Bus.h"
#pragma once
class Timetable
{
	std::string _fileName;
	std::vector<Bus> _buses;
public:
	
	Timetable(std::string fileName);
	void GetData();
	void AddRecord(Bus bus);
	void DeleteRecord(int busId);
	void UpdateRecord(Bus updatedBus);
	std::vector<Bus> GetRecords();
	std::vector<Bus> FindSuitableBuses(std::string destination, tm arrivalTime);
	~Timetable();

private:
	std::string TrimString(std::string const& str);
};


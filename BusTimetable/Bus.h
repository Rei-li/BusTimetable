#include <string>
#include <ctime>
#pragma once

class Bus
{
	int _id, _number;
	std::string _busType, _destination;
	tm _departureTime, _arrivalTime;
public:
	Bus::Bus();
	Bus(int id, int number, std::string busType, std::string destination, tm departureTime, tm arrivalTime);
	Bus(int number, std::string busType, std::string destination, tm departureTime, tm arrivalTime);
	Bus(int number, std::string destination, tm departureTime, tm arrivalTime);
	int GetId();
	void SetId(int id);
	tm GetArrivalTime();
	std::string ToString();
	~Bus();
};


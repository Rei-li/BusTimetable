#include "stdafx.h"
#include "Bus.h"
#include <string>

using namespace std;

Bus::Bus()
{
}

Bus::Bus(int id, int number, string busType, string destination, tm departureTime, tm arrivalTime)
{
	_id = id;
	_number = number;
	_busType = busType;
	_destination = destination;
	_departureTime = departureTime;
	_arrivalTime = arrivalTime;
}

Bus::Bus(int number, string busType, string destination, tm departureTime, tm arrivalTime)
{
	_number = number;
	_busType = busType;
	_destination = destination;
	_departureTime = departureTime;
	_arrivalTime = arrivalTime;
}

Bus::Bus(int number, string destination, tm departureTime, tm arrivalTime)
{
	_number = number;
	_destination = destination;
	_departureTime = departureTime;
	_arrivalTime = arrivalTime;
}

int Bus::GetId()
{
	return _id;
}

void Bus::SetId(int id)
{
	_id = id;
}

tm Bus::GetArrivalTime()
{
	return _arrivalTime;
}

string Bus::ToString()
{
	return string(std::to_string(_id) + ", " +  std::to_string(_number) + ", " + _busType + ", " + _destination +  ", " + std::to_string( _departureTime.tm_hour ) + ":"+ std::to_string(_departureTime.tm_min) + ", " + std::to_string(_arrivalTime.tm_hour) + ":" + std::to_string(_arrivalTime.tm_min));
}

Bus::~Bus()
{
}

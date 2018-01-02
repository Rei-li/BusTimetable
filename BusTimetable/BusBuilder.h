#include <string>
#include <vector>
#include "Bus.h"

#pragma once

class BusBuilder
{
public:	
	static Bus BuildBus(std::vector<std::string> busFields);
	static tm parseTimeString(std::string timeString);

private:	
	BusBuilder() {};
};


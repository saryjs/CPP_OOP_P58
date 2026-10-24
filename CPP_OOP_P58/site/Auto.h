#pragma once
#include "Site.h"

class Auto : public Site {
private:
	double      year;
	std::string gear;
public:
	double      getYear() const;
	Auto*		setYear(double);
	std::string getGear() const;
	Auto*		setGear(std::string);
};
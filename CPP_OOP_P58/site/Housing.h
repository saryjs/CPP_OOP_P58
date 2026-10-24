#pragma once
#include "Site.h"

class Housing : public Site {
private:
	double      square;
	std::string loctaion;
public:
	double      getSquare() const;
	Housing*	setSquare(double);
	std::string getLocation() const;
	Housing*	setLocation(std::string);
};
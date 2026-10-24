#include "Auto.h"

double Auto::getYear() const {
	return year;
}

Auto* Auto::setYear(double year) {
	this->year = year;
	return this;
}
std::string Auto::getGear() const {
	return gear;
}

Auto* Auto::setGear(std::string gear) {
	this->gear = gear;
	return this;
}
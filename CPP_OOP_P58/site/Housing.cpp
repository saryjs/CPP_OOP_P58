#include "Housing.h"

double Housing::getSquare() const {
	return square;
}

Housing* Housing::setSquare(double square) {
	this->square = square;
	return this;
}
std::string Housing::getLocation() const {
	return location;
}

Housing* Housing::setLocation(std::string location) {
	this->location = location;
	return this;
}
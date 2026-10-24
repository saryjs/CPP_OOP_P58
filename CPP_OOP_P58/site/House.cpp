#include "House.h"
#include <format>

double House::getAddress() const {
	return address;
}

House* House::setAddress(double address) {
	this->address = address;
	return this;
}

std::string House::toString() const {
	return std::format(
		"{} (at: {}) {}sqr. {} hrn {}",
		getName(),
		address,
		getSquare(),
		getPrice(),
		getLocation()
	);
}
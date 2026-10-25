#include "House.h"
#include <format>

std::string House::getAddress() const {
	return address;
}

House* House::setAddress(std::string address) {
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
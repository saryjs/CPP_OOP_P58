#include "Car.h"
#include <format>

double Car::getGas() const {
	return gas_type;
}

Car* Car::setGas(std::string gas_type) {
	this->gas_type = gas_type;
	return this;
}

std::string Car::toString() const {
	return std::format(
		"{} ({}, {}) {} hrn {}",
		getName(),
		gas_type,
		getGear(),
		getPrice(),
		getYear()
	);
}
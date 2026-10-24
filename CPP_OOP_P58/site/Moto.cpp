#include "Moto.h"
#include <format>

double Moto::getGas() const {
	return gas_type;
}

Moto* Moto::setGas(double gas_type) {
	this->gas_type = gas_type;
	return this;
}

std::string Moto::toString() const {
	return std::format(
		"{} ({}, {}) {} hrn {}",
		getName(),
		gas_type,
		getGear(),
		getPrice(),
		getYear()
	);
}
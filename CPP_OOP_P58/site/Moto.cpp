#include "Moto.h"
#include <format>

std::string Moto::getGas() const {
	return gas_type;
}

Moto* Moto::setGas(std::string gas_type) {
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
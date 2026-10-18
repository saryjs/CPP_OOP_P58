#include "Laptop.h"
#include <format>

std::string Laptop::getHardware() const {
	return hardware;
}
Laptop* Laptop::setHardware(std::string hardware) {
	this->hardware = hardware;
	return this;
}
std::string Laptop::toString() const {
	return std::format("{} {} UAH, {} ({} W)",
		getName(),
		getPrice(),
		hardware,
		getPower()
	);
};
#include "Laptop.h"
#include <format>

std::string Laptop::getHardware() const {
	return hardware;
}
void Laptop::setHardware(std::string hardware) {
	this->hardware = hardware;
}
std::string Laptop::toString() {
	return std::format("{} {} UAH, {} ({} W)",
		getName(),
		getPrice(),
		hardware,
		getPower()
	);
};
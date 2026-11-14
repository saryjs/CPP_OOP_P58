#include "Laptop.h"
#include <format>

std::string Laptop::getHardware() const {
	return hardware;
}

Laptop* Laptop::setHardware(std::string hardware) {
	this->hardware = hardware;
	return this;  // "fluent interface" - каскадне встановлення властивостей
}

std::string Laptop::toString() const {
	return std::format("{} {} hrn, {} ({} W)",
		getName(),
		getPrice(),
		hardware,
		getPower()
	);
}

std::ostream& operator <<(std::ostream& out, const Laptop& obj) {
	out << obj.toString();
	return out;
}

std::ostream& operator <<(std::ostream& out, const Laptop* obj) {
	out << *obj; // розіменування покажчика (Dereferencing)
	return out;
}
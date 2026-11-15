#include "Keyboard.h"
#include <format>
#include <iostream>

std::string Keyboard::getType() const {
	return type;
}

Keyboard* Keyboard::setType(std::string type) {
	this->type = type;
	return this;
}

std::string Keyboard::toString() const {
	return std::format("{} {} hrn, {} ({} Connection)",
		getName(),
		getPrice(),
		type,
		getConnection()
	);
}

std::ostream& operator <<(std::ostream& out, const Keyboard& obj) {
	out << obj.toString();
	return out;
}

std::ostream& operator <<(std::ostream& out, const Keyboard* obj) {
	out << *obj;
	return out;
}
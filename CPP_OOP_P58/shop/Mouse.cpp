#include "Mouse.h"
#include <format>
#include <iostream>

int Mouse::getDpi() const {
	return dpi;
}

Mouse* Mouse::setDpi(int dpi) {
	if (dpi <= 0) {
		throw std::range_error("Dpi less than zero");
	}
	this->dpi = dpi;
	return this;
}

std::string Mouse::toString() const {
	return std::format("{} {} hrn, {} DPI ({} Connection)",
		getName(),
		getPrice(),
		dpi,
		getConnection()
	);
}

std::ostream& operator <<(std::ostream& out, const Mouse& obj) {
	out << obj.toString();
	return out;
}

std::ostream& operator <<(std::ostream& out, const Mouse* obj) {
	out << *obj;
	return out;
}
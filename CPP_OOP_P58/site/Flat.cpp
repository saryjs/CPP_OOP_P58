#include "Flat.h"
#include <format>

double Flat::getRoom() const {
	return room;
}

Flat* Flat::setRoom(double room) {
	this->room = room;
	return this;
}

std::string Flat::toString() const {
	return std::format(
		"{} (#{}) {}sqr. {} hrn {}",
		getName(),
		room,
		getSquare(),
		getPrice(),
		getLocation()
	);
}
#include <string>
#include "Site.h"

std::string Site::getName() const {
	return name;
}

Site* Site::setName(std::string name) {
	this->name = name;
	return this;
}

double Site::getPrice() const {
	return price;
}

Site* Site::setPrice(double price) {
	this->price = price;
	return this;
}
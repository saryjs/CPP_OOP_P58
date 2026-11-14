#pragma once
#include "Electrical.h"
#include <iostream>

class Laptop : public Electrical {
private:
	std::string hardware;
public:
	std::string getHardware() const;
	Laptop* setHardware(std::string);
	std::string toString() const override;  // override - переозначення батьківського методу

	Laptop() {}
	Laptop(const Laptop& other) : hardware{other.hardware} {}
	Laptop(Laptop&& other) noexcept : hardware{ other.hardware } {}
	~Laptop() {}

	//std::ostream& operator <<(std::ostream& out, const Laptop& obj);
	//std::ostream& operator <<(std::ostream& out, const Laptop* obj);
};
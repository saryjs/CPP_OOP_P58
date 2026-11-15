#pragma once
#include "Periphery.h"
#include <iostream>

class Keyboard : public Periphery {
private:
	std::string type;
public:
	std::string getType() const;
	Keyboard* setType(std::string);
	std::string toString() const override;

	Keyboard() : type{"Default keyboard type"} {}
	Keyboard(const Keyboard& other) : type{ other.type } {}
	Keyboard(Keyboard&& other) noexcept : type{ other.type } {}
	~Keyboard() {}
};
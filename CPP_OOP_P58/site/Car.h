#pragma once
#include "Auto.h"

class Car : public Auto {
private:
	std::string      gas_type;
public:
	std::string      getGas() const;
	Car*			 setGas(std::string);
	std::string      toString() const override;
};
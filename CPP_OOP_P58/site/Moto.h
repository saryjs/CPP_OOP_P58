#pragma once
#include "Auto.h"

class Moto : public Auto {
private:
	std::string      gas_type;
public:
	std::string      getGas() const;
	Moto*			 setGas(std::string);
	std::string      toString() const override;
};
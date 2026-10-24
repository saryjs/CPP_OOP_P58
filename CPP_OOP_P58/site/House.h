#pragma once
#include "Housing.h"

class House : public Housing {
private:
	std::string      address;
public:
	std::string      getAddress() const;
	House*			 setAddress(std::string);
	std::string		 toString() const override;
};
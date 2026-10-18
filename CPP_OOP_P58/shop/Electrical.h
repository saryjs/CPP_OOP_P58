#pragma once
#include "Product.h"

class Electrical : public Product {
private:
	double power;
public:
	double		  getPower() const;
	Electrical*   setPower(double);

	virtual std::string	toString() const = 0;
};
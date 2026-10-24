#pragma once
#include <string>

class Site {
private:
	std::string name;
	double      price;
public:
	std::string getName() const;
	Site*		setName(std::string);
	double      getPrice() const;
	Site*		setPrice(double);

	virtual std::string toString() const = 0;
};
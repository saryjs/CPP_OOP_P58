#pragma once
#include "Product.h"

class Periphery : public Product {
private:
	std::string connection;
public:
	std::string      getConnection() const;
	Periphery*		 setConnection(std::string);

	virtual std::string toString() const = 0;
};
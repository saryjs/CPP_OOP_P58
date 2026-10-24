#pragma once
#include "Housing.h"

class Flat : public Housing {
private:
	double      room;
public:
	double      getRoom() const;
	Flat*		setRoom(double);
	std::string toString() const override;
};
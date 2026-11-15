#pragma once
#include "Periphery.h"
#include <iostream>

class Mouse : public Periphery {
private:
	int dpi;
public:
	int getDpi() const;
	Mouse* setDpi(int);
	std::string toString() const override;

	Mouse() : dpi{ 800 } {}
	Mouse(const Mouse& other) : dpi{ other.dpi } {}
	Mouse(Mouse&& other) noexcept : dpi{ other.dpi } {}
	~Mouse() {}
};
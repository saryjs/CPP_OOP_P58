#include "fraction.h"
#include <format>

fraction_t::fraction_t() {
	numerator = 0;
	denominator = 1;
}
fraction_t::fraction_t(int n) {
	numerator = n;
	denominator = 1;
}
fraction_t::fraction_t(int numerator, int denominator) :
	numerator{ numerator }, denominator{ denominator }
{
}

int fraction_t::get_numerator() {
	return numerator;
}
int fraction_t::get_denominator() {
	return denominator;
}
void fraction_t::set_numerator(int numerator) {
	this->numerator = numerator;
}
void fraction_t::set_denominator(int denominator) {
	this->denominator = denominator;
}

std::string fraction_t::to_string() {
	// placeholders
	//                   v   v - placeholders
	return std::format("({}/{})", numerator, denominator);
	//                                ^           ^
	// data to place instead of placeholders
}
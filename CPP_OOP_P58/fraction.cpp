#include "fraction.h"
#include <format>
#include <iostream>

fraction_t::fraction_t() {
	numerator = 0;
	denominator = 1;
	name = NULL;
}
fraction_t::fraction_t(int n) {
	numerator = n;
	denominator = 1;
	name = NULL;
}
fraction_t::fraction_t(int numerator, int denominator) :
	numerator{ numerator }, denominator{ denominator }
{
	name = NULL;
}
fraction_t::fraction_t(int numerator, int denominator, char* name) :
	numerator{ numerator }, denominator{ denominator }, name{ name }
{
}

fraction_t::fraction_t(fraction_t& other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;

	if (other.name != NULL) {
		this->name = new char[strnlen_s(other.name, 100) + 1];
		strcpy_s(this->name, 100, other.name);
		std::cout << "Copy constructor: copy from " 
			<< (void*)other.name 
			<< " to " 
			<< (void*)this->name 
			<< std::endl;
	}
	else {
		this->name = NULL;
	}
}

char* fraction_t::get_name() {
	return name;
}
void fraction_t::set_name(char* name) {
	this->name = name;
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
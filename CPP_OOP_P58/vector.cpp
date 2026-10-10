#include "vector.h"
#include <format>
#include <iostream>

vector2_t::vector2_t() {
	x = 0;
	y = 0;
}
vector2_t::vector2_t(float x) {
	this->x = x;
	y = 0;
}
vector2_t::vector2_t(float x, float y) :
	x{ x }, y{ y }
{
	name = NULL;
}
vector2_t::vector2_t(float x, float y, char* name) :
	x{ x }, y{ y }, name{ name }
{
}

float vector2_t::get_x() {
	return x;
}
float vector2_t::get_y() {
	return y;
}
void vector2_t::set_x(float x) {
	this->x = x;
}
void vector2_t::set_y(float y) {
	this->y = y;
}

std::string vector2_t::to_string() {
	return std::format("({};{})", x, y);
}
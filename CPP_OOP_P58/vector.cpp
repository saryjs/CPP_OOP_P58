#define _CRT_SECURE_NO_WARNINGS
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

vector2_t::vector2_t(vector2_t& other) {
	this->x = other.x;
	this->y = other.y;
	// для референсного ресурсу створюємо копію
	if (other.name != NULL) {
		size_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy(this->name, other.name);
		// std::cout << "Copy constructor: copy from " << (void*)other.name << " to "
		// 	<< (void*)(this->name) << std::endl;
	}
	else {
		this->name = NULL;
	}
}
vector2_t::vector2_t(vector2_t&& other) noexcept {
	this->x = other.x;
	this->y = other.y;
	this->name = other.name;
	other.name = NULL;
	std::cout << "Move constructor: take from " << (void*)other.name << std::endl;

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

vector2_t::~vector2_t() {
	if (name != NULL) {
		delete[] name;
	}
}
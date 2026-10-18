#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"
#include <format>
#include <iostream>

vector2_t::vector2_t() {
	x = 0;
	y = 0;
	name = NULL;
}
vector2_t::vector2_t(float x) {
	this->x = x;
	y = 0;
	name = NULL;
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
vector2_t vector2_t::operator +(const vector2_t& other) const {
	char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "+");
		strcpy(new_name + len1 + 1, other.name);
	}
	return vector2_t(
		this->x + other.x, this->y + other.y, new_name);
}
vector2_t vector2_t::operator -(const vector2_t& other) const {
	char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "-");
		strcpy(new_name + len1 + 1, other.name);
	}
	return vector2_t(
		this->x - other.x, this->y - other.y, new_name);
}

vector2_t operator *(const vector2_t& f1, const vector2_t& f2) {
	char* ret_name = f1.name + "+" + f2.name;
	return vector2_t(
		f1.x * f2.x,
		f1.y * f2.y,
		ret_name);
}
vector2_t operator /(const vector2_t& f1, const vector2_t& f2) {
	return vector2_t(
		f1.x / f2.x,
		f1.y / f2.y
	);
}

vector2_t& vector2_t::operator =(const vector2_t& other) {
	delete[] this->name;
	this->x = other.x;
	this->y = other.y;
	if (other.name != NULL) {
		size_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy(this->name, other.name);
		std::cout << "Copy assignment: copy from " << (void*)other.name << " to "
			<< (void*)(this->name) << std::endl;
	}
	else {
		this->name = NULL;
	}
	return *this;
}

vector2_t& vector2_t::operator =(vector2_t&& other) noexcept {
	this->x = other.x;
	this->y = other.y;
	this->name = other.name;
	other.name = NULL;
	std::cout << "Move assignment: take from " << (void*)this->name << std::endl;
	return *this;
}

std::ostream& operator <<(std::ostream& out, const vector2_t& f) {
	out << f.x << " ; " << f.y << "(" << f.name << ")";
	return out;
}

vector2_t operator -(vector2_t& f) {
	return vector2_t(
		-f.get_x(),
		f.get_y()
	);
}

void vector2_t::operator +=(const vector2_t& other) {
	this->x = this->x + other.x;
	this->y = this->y + other.y;
}
void vector2_t::operator +=(int n) {
	this->x += n * this->y;
}
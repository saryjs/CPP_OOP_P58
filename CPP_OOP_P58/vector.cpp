#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"
#include <format>
#include <iostream>

//template<typename T>
//vector2_t<T>::vector2_t() {
//	x = 0;
//	y = 0;
//	name = NULL;
//}
//template<typename T>
//vector2_t<T>::vector2_t(T x) {
//	this->x = x;
//	y = 0;
//	name = NULL;
//}
//template<typename T>
//vector2_t<T>::vector2_t(T x, T y) :
//	x{ x }, y{ y }
//{
//	name = NULL;
//}
//template<typename T>
//vector2_t<T>::vector2_t(T x, T y, char* name) :
//	x{ x }, y{ y }, name{ name }
//{
//}
//
//template<typename T>
//vector2_t<T>::vector2_t(const vector2_t& other) {
//	this->x = other.x;
//	this->y = other.y;
//	// для референсного ресурсу створюємо копію
//	if (other.name != NULL) {
//		size_t len = strlen(other.name) + 1;
//		this->name = new char[len];
//		strcpy(this->name, other.name);
//		// std::cout << "Copy constructor: copy from " << (void*)other.name << " to "
//		// 	<< (void*)(this->name) << std::endl;
//	}
//	else {
//		this->name = NULL;
//	}
//}
//template<typename T>
//vector2_t<T>::vector2_t(vector2_t&& other) noexcept {
//	this->x = other.x;
//	this->y = other.y;
//	this->name = other.name;
//	other.name = NULL;
//	std::cout << "Move constructor: take from " << (void*)other.name << std::endl;
//
//}
//
//template<typename T>
//T vector2_t<T>::get_x() {
//	return x;
//}
//template<typename T>
//T vector2_t<T>::get_y() {
//	return y;
//}
//template<typename T>
//void vector2_t<T>::set_x(T x) {
//	this->x = x;
//}
//template<typename T>
//void vector2_t<T>::set_y(T y) {
//	this->y = y;
//}
//
//template<typename T>
//std::string vector2_t<T>::to_string() {
//	return std::format("({};{})", x, y);
//}
//
//template<typename T>
//vector2_t<T>::~vector2_t() {
//	if (name != NULL) {
//		delete[] name;
//	}
//}
//template<typename T>
//vector2_t<T> vector2_t<T>::operator +(const vector2_t& other) const {
//	char* new_name = NULL;
//	if (this->name != NULL && other.name != NULL) {
//		size_t len1 = strlen(this->name);
//		size_t len = len1 + strlen(other.name) + 2;
//		new_name = new char[len];
//		strcpy(new_name, this->name);
//		strcpy(new_name + len1, "+");
//		strcpy(new_name + len1 + 1, other.name);
//	}
//	return vector2_t<T>(
//		this->x + other.x, this->y + other.y, new_name);
//}
//template<typename T>
//vector2_t<T> vector2_t<T>::operator -(const vector2_t& other) const {
//	char* new_name = NULL;
//	if (this->name != NULL && other.name != NULL) {
//		size_t len1 = strlen(this->name);
//		size_t len = len1 + strlen(other.name) + 2;
//		new_name = new char[len];
//		strcpy(new_name, this->name);
//		strcpy(new_name + len1, "-");
//		strcpy(new_name + len1 + 1, other.name);
//	}
//	return vector2_t<T>(
//		this->x - other.x, this->y - other.y, new_name);
//}
//
//template<typename T>
//vector2_t<T> operator *(const vector2_t<T>& f1, const vector2_t<T>& f2) {
//	char* ret_name = f1.name;
//	return vector2_t<T>(
//		f1.x * f2.x,
//		f1.y * f2.y,
//		ret_name);
//}
//template<typename T>
//vector2_t<T> operator /(const vector2_t<T>& f1, const vector2_t<T>& f2) {
//	char* ret_name = f1.name;
//	return vector2_t<T>(
//		f1.x / f2.x,
//		f1.y / f2.y,
//		ret_name
//	);
//}
//
//template<typename T>
//vector2_t<T>& vector2_t<T>::operator =(const vector2_t<T>& other) {
//	delete[] this->name;
//	this->x = other.x;
//	this->y = other.y;
//	if (other.name != NULL) {
//		size_t len = strlen(other.name) + 1;
//		this->name = new char[len];
//		strcpy(this->name, other.name);
//		std::cout << "Copy assignment: copy from " << (void*)other.name << " to "
//			<< (void*)(this->name) << std::endl;
//	}
//	else {
//		this->name = NULL;
//	}
//	return *this;
//}
//
//template<typename T>
//vector2_t<T>& vector2_t<T>::operator =(vector2_t<T>&& other) noexcept {
//	this->x = other.x;
//	this->y = other.y;
//	this->name = other.name;
//	other.name = NULL;
//	std::cout << "Move assignment: take from " << (void*)this->name << std::endl;
//	return *this;
//}
//
//template<typename T>
//std::ostream& operator <<(std::ostream& out, const vector2_t<T>& f) {
//	out << f.x << " ; " << f.y;// << "(" << f.name << ")";
//	return out;
//}
//
//template<typename T>
//vector2_t<T> operator -(vector2_t<T>& f) {
//	return vector2_t<T>(
//		-f.get_x(),
//		f.get_y()
//	);
//}
//
//template<typename T>
//void vector2_t<T>::operator +=(const vector2_t<T>& other) {
//	this->x = this->x + other.x;
//	this->y = this->y + other.y;
//}
//template<typename T>
//void vector2_t<T>::operator +=(T n) {
//	this->x = n + this->x;
//	this->y = n + this->y;
//}
//template<typename T>
//void vector2_t<T>::operator -=(const vector2_t<T>& other) {
//	this->x = this->x - other.x;
//	this->y = this->y - other.y;
//}
//template<typename T>
//void vector2_t<T>::operator -=(T n) {
//	this->x = this->x - n;
//	this->y = this->y - n;
//}
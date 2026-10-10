//#include "vector.h"
//#include <format>
//#include <iostream>
//
//vector2_t::vector2_t() {
//	x = 0;
//	y = 0;
//}
//vector2_t::vector2_t(float x) {
//	this->x = x;
//	y = 0;
//}
//vector2_t::vector2_t(float x, float y) :
//	x{ x }, y{ y }
//{
//	name = NULL;
//}
//vector2_t::vector2_t(float x, float y, char* name) :
//	x{ x }, y{ y }, name{ name }
//{
//}
//
//vector2_t::vector2_t(vector2_t& other) {
//	this->x = other.x;
//	this->y = other.y;
//
//	if (other.name != NULL) {
//		this->name = new char[strlen(other.name) + 1];
//		strcpy_s(this->name, 100, other.name);
//		std::cout << "Copy constructor: copy from "
//			<< (void*)other.name
//			<< " to "
//			<< (void*)(this->name)
//			<< std::endl;
//	}
//	else {
//		this->name = NULL;
//	}
//}
//vector2_t::vector2_t(vector2_t&& other) {
//	// викликається тоді, коли інший
//	// об'єкт (other) підлягає знащенню, наприклад, коли він передається
//	// як результат роботи функції.
//
//	// Конструктор перенесення може "забрати" ресурс іншого об'єкта
//	// замість того, щоб створювати копію. Але, щоб знищення не запустилось
//	// автоматично, слід підмінити ресурс іншого об'єкту на NULL
//
//}
//
//float vector2_t::get_x() {
//	return x;
//}
//float vector2_t::get_y() {
//	return y;
//}
//void vector2_t::set_x(float x) {
//	this->x = x;
//}
//void vector2_t::set_y(float y) {
//	this->y = y;
//}
//
//std::string vector2_t::to_string() {
//	return std::format("({};{})", x, y);
//}
//
//vector2_t::~vector2_t() {
//	if (name != NULL) {
//		delete[] name;
//	}
//}
#pragma once
#include <string>
#include <format>
#include <iostream>

template<typename T>
class vector2_t {
private:
	T x;
	T y;
	char* name;
public:
	T get_x() {
		return x;
	};
	T get_y() {
		return y;
	};
	void set_x(T x) {
		this->x = x;
	};
	void set_y(T y) {
		this->y = y;
	};

	char* get_name() {
		return name;
	};
	void set_name(char* name) {
		this->name = name;
	};

	std::string to_string() {
		return std::format("({};{})", x, y);
	};

	vector2_t() {
		x = 0;
		y = 0;
		name = NULL;
	};
	vector2_t(T x) {
		this->x = x;
		y = 0;
		name = NULL;
	};
	vector2_t(T x, T y) {
		this->x = x;
		this->y = y;
		name = NULL;
	};
	vector2_t(T x, T y, char* name):
		x{ x }, y{ y }, name{ name }
	{
	};

	vector2_t(const vector2_t& other) {
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
	};
	vector2_t(vector2_t&& other) noexcept {
		this->x = other.x;
		this->y = other.y;
		this->name = other.name;
		other.name = NULL;
		std::cout << "Move constructor: take from " << (void*)other.name << std::endl;
	}; // move constructor
	~vector2_t() {
		if (name != NULL) {
			delete[] name;
		}
	};

	vector2_t operator +(const vector2_t& other) const {
		char* new_name = NULL;
		if (this->name != NULL && other.name != NULL) {
			size_t len1 = strlen(this->name);
			size_t len = len1 + strlen(other.name) + 2;
			new_name = new char[len];
			strcpy(new_name, this->name);
			strcpy(new_name + len1, "+");
			strcpy(new_name + len1 + 1, other.name);
		}
		return vector2_t<T>(
			this->x + other.x, this->y + other.y, new_name);
	};
	vector2_t operator -(const vector2_t& other) const {
		char* new_name = NULL;
		if (this->name != NULL && other.name != NULL) {
			size_t len1 = strlen(this->name);
			size_t len = len1 + strlen(other.name) + 2;
			new_name = new char[len];
			strcpy(new_name, this->name);
			strcpy(new_name + len1, "-");
			strcpy(new_name + len1 + 1, other.name);
		}
		return vector2_t<T>(
			this->x - other.x, this->y - other.y, new_name);
	};

	vector2_t& operator =(const vector2_t& other){
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
	}; // copy
	vector2_t& operator =(vector2_t&& other) noexcept {
		this->x = other.x;
		this->y = other.y;
		this->name = other.name;
		other.name = NULL;
		std::cout << "Move assignment: take from " << (void*)this->name << std::endl;
		return *this;
	}; // move

	void operator +=(const vector2_t& other) {
		this->x = this->x + other.x;
		this->y = this->y + other.y;
	};
	void operator +=(T n) {
		this->x = n + this->x;
		this->y = n + this->y;
	};
	void operator -=(const vector2_t& other) {
		this->x = this->x - other.x;
		this->y = this->y - other.y;
	};
	void operator -=(T n) {
		this->x = this->x - n;
		this->y = this->y - n;
	};
	
	friend vector2_t operator *(const vector2_t& f1, const vector2_t& f2) {
		char* ret_name = f1.name;
		return vector2_t<T>(
			f1.x * f2.x,
			f1.y * f2.y,
			ret_name);
	};
	friend vector2_t operator /(const vector2_t& f1, const vector2_t& f2) {
		char* ret_name = f1.name;
		return vector2_t<T>(
			f1.x / f2.x,
			f1.y / f2.y,
			ret_name);
	};

	friend std::ostream& operator <<(std::ostream& out, const vector2_t& f) {
		out << f.x << " ; " << f.y;
		return out;
	};
};

template<typename T>
std::ostream& operator <<(std::ostream& out, const vector2_t<T>& f) {
	out << f.x << " ; " << f.y;// << "(" << f.name << ")";
	return out;
};

template<typename T>
vector2_t<T> operator -(vector2_t<T>& f) {
	return vector2_t<T>(
		-f.get_x(),
		f.get_y()
	);
};

template<typename T>
vector2_t<T> operator *(const vector2_t<T>& f1, const vector2_t<T>& f2) {
	char* ret_name = f1.name;
	return vector2_t<T>(
		f1.x * f2.x,
		f1.y * f2.y,
		ret_name);
};
template<typename T>
vector2_t<T> operator /(const vector2_t<T>& f1, const vector2_t<T>& f2) {
	char* ret_name = f1.name;
	return vector2_t<T>(
		f1.x / f2.x,
		f1.y / f2.y,
		ret_name);
};


#pragma once
#include <string>

class vector2_t {
private:
	float x;
	float y;
	char* name;
public:
	float get_x();
	float get_y();
	void set_x(float);
	void set_y(float);

	char* get_name();
	void set_name(char*);

	std::string to_string();

	vector2_t();
	vector2_t(float);
	vector2_t(float, float);
	vector2_t(float, float, char*);

	vector2_t(vector2_t&);
	vector2_t(vector2_t&&) noexcept; // move constructor
	~vector2_t();

	vector2_t operator +(const vector2_t& other) const;
	vector2_t operator -(const vector2_t& other) const;

	vector2_t& operator =(const vector2_t& other); // copy
	vector2_t& operator =(vector2_t&& other) noexcept; // move

	void operator +=(const vector2_t& other);
	void operator +=(int n);
	void operator -=(const vector2_t& other);
	void operator -=(int n);
	
	friend vector2_t operator *(const vector2_t& f1, const vector2_t& f2);
	friend vector2_t operator /(const vector2_t& f1, const vector2_t& f2);

	friend std::ostream& operator <<(std::ostream& out, const vector2_t& f);
};

std::ostream& operator <<(std::ostream& out,const vector2_t& f);

vector2_t operator -(vector2_t& other);

vector2_t operator *(const vector2_t& f1, const vector2_t& f2);
vector2_t operator /(const vector2_t& f1, const vector2_t& f2);
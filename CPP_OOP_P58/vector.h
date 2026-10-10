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
};
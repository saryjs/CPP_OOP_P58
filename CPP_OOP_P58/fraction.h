#pragma once
#include <string>

class fraction_t {
private:
	int numerator;
	int denominator;
	char* name;
public:
	int get_numerator();
	int get_denominator();
	void set_numerator(int);
	void set_denominator(int);

	char* get_name();
	void set_name(char*);

	std::string to_string();

	fraction_t();  // constructor
	fraction_t(int);
	fraction_t(int, int);
	fraction_t(int, int, char*);

	fraction_t(fraction_t&);
	//fraction_t(fraction_t&&);
	//
	~fraction_t(); // destructor
};
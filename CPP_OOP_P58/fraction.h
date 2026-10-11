#pragma once
#include <string>
#include <iostream>

class fraction_t {             // клас - це тип даних, тому є традиції додавати "_t"
private:                       // склад класу поділяється за "видимістю" на декілька категорій
	int numerator;             // поле - "змінна" в середині класу
	int denominator;           // набір полів називають "характеристиками" класу
	char* name;
	int gcd(int a, int b);     // private method (Great Common Divider)
	void reduce();			   // скорочення дробу
public:                        // За рекомендаціями ООП поля мають бути приватними, 
	int get_numerator() const;       // а для доступу до них створюють методи ("функції"), що називають
	int get_denominator() const;     // аксесорами (які поділяють на геттери та сеттери)
	void set_numerator(int);   // набір методів класу також називають "поведінкою"
	void set_denominator(int);
	char* get_name() const;
	void set_name(char*);
	std::string to_string() const;

	fraction_t();                // конструктори - спец. методи, які автоматично запускаються
	fraction_t(int);             // коли створюються об'єкти даного класу. Вони не мають 
	fraction_t(int, int);        // типу повернення і збігаються за назвою з іменем класу
	fraction_t(int, int, char*); // Конструкторів може бути декілька за правилами перевантаження
	fraction_t(fraction_t&);     // Окремий тип конструкторів: конструктор копіювання
	fraction_t(fraction_t&&) noexcept;  // конструктор переносу (move constructor)

	~fraction_t();               // деструктор - викликається при знищенні об'єкта

	static fraction_t decil() {  // статичні методи - методи класів (не об'єктів)
		fraction_t d(1, 10, new char[] {"Decil"});
		return d;
	}

	// оператори: С++ надає можливість перевантажувати оператори з автоматичним
	// включенням наших об'єктів до арифметичних та інших виразів, на кшталт А + В.
	// Перевантаження - через ключове слово "operator", для пришвидшення роботи
	// другий аргумент (other) передається за посиланням (&) і для унеможливлення
	// його змін додається const
	fraction_t operator +(const fraction_t& other);
	fraction_t operator -(const fraction_t& other);
	// Особливу роль шрають оператори присвоювання (=)
	// Вони також поділяються на оператори копіювання та перенесення
	fraction_t& operator =(const fraction_t& other); // copy
	fraction_t& operator =(fraction_t&& other) noexcept; // move

	void operator +=(const fraction_t& other);
	void operator +=(int n);

	// "friend" methods - outside functions, which have access to private fields
	friend fraction_t operator *(const fraction_t& f1, const fraction_t& f2);
};

// operations can be outside of classes
// traditionally operators that dont change objects (*, /, etc) are outside
// also some operators, which have a first parameter get *not* the given object
std::ostream& operator <<(std::ostream& out, const fraction_t& f);
// while the ones that do (+=, =, etc) are inside

// унарні оператори - приймають один об'єкт
fraction_t operator -(const fraction_t& other);

fraction_t operator *(const fraction_t& f1, const fraction_t& f2);
fraction_t operator /(const fraction_t& f1, const fraction_t& f2);
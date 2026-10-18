#include "intro.h"
#include "fraction.h"
#include "vector.h"
#include <iostream>

void intro() {
	// запуск демонстрації
	std::cout << "Intro to OOP" << std::endl;
	// створення об'єктів
	fraction_t frac1;   // статичне оголошення - об'єкт у стеку
	fraction_t* frac2 = new fraction_t;  // динамічне оголошення - об'єкт у "купі"
	std::cout                                // без ініціалізації бачимо випадкові числа 
		<< frac1 << std::endl    // до об'єктів звертаємось через "."
		<< frac2 << std::endl;  // до покажчиків - через "->"

	// за допомогою конструкторів з параметрами можна задавати початкові значення
	fraction_t frac3(10);
	fraction_t* frac4 = new fraction_t(1, 10);
	std::cout
		<< frac3 << std::endl
		<< frac4 << std::endl;

	fraction_t frac5(1, 2, new char[] {"Half"});
	fraction_t* frac6 = new fraction_t(frac5);
	std::cout
		<< frac5 << std::endl
		<< frac6 << std::endl;

	fraction_t d = std::move( fraction_t::decil() );
	std::cout
		<< d << std::endl;

	std::cout << frac5 << " + " << d
		<< " = " << (frac5 + d) << std::endl;

	std::cout << frac5 << " - " << d
		<< " = " << (frac5 - d) << std::endl;

	std::cout
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl;

	std::cout << "-----------------------------" << std::endl;
	fraction_t f; // default constructor
	std::cout << f << std::endl;
	f = d; // copy assigment (operator =)
	std::cout << f << std::endl;
	f = f + frac5;
	std::cout << f << std::endl;

	std::cout << "-----------------------------" << std::endl;
	f = f * frac5;
	std::cout << f << std::endl;
	std::cout << "-----------------------------" << std::endl;
	f = f / frac5;
	std::cout << f << std::endl;
	std::cout << "-----------------------------" << std::endl;
	f = f / frac5;
	std::cout << f << std::endl;
	std::cout << -f << std::endl;
	std::cout << "-----------------------------" << std::endl;
	f += 1;
	std::cout << f << std::endl;
	f += frac5;
	std::cout << f << std::endl;


	std::cout
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl
		<< std::endl;

	delete frac2;
	delete frac4;
	delete frac6;

	vector2_t vect1(6, 4, new char[] {"Vector 1"});
	vector2_t* vect2 = new vector2_t(5, 0.5);
	std::cout
		<< vect1.to_string()
		<< vect2->to_string();

	vector2_t vect3(5, 10, new char[] {"Vector 3"});
	vector2_t* vect4 = new vector2_t(vect3);
	vector2_t* vect5 = new vector2_t(*vect4);
	std::cout << std::endl
		<< "Original vector: " << vect3.to_string() << std::endl
		<< "Copied vector: " << vect4->to_string() << std::endl
		<< "Copied copied vector: " << vect5->to_string() << std::endl;

	std::cout << "----------Vector1-------------" << std::endl;
	vector2_t vec(0,0, new char[] {"Name"});
	std::cout << vec << std::endl;
	vec = vect1;
	std::cout << vec << std::endl;
	vec = vec + vect3;
	std::cout << vec << std::endl;

	std::cout << "----------Vector2-------------" << std::endl;
	vec = vec * vect3;
	std::cout << vec << std::endl;
	std::cout << "----------Vector3-------------" << std::endl;
	vec = vec / vect3;
	std::cout << vec << std::endl;
	std::cout << "----------Vector4-------------" << std::endl;
	vec = vec / vect3;
	std::cout << vec << std::endl;
	std::cout << -vec << std::endl;
	std::cout << "----------Vector5-------------" << std::endl;
	vec += 1;
	std::cout << vec << std::endl;
	vec += vect3;
	std::cout << vec << std::endl;

	delete vect2;
	delete vect4;
	delete vect5;
}

/*
ООП. Вступ.
Парадигма - термін, що поєднує традиції, прийоми, методики тощо.
У програмувнні існують декілька парадигм:
 - Імперативна парадигма (в яку входить процедурний підхід)
	програма вважається послідовністю інструкцій, серед яких лише одна
	виконується у даний момент часу. Окремі інструкції програми дозволяють
	змінувати порядок виконання (умови, цикли)
	Процедурний підхід - організація коду у вигляді набору процедур, тіла
	яких є послідовностями інструкцій
 - Функціональна парадигма - базується на матиматично-функціональних засадах
	програма вважається "конвертом" у якому лежить інструкція, що слід
	зробити, та новий "конверт" над яким слід виконати цю дію.
	Представники: LISP, Python, J, TCL, Haskel
 - Декаративна парадигма (в яку входить логічна) - базується на теорії знань
	програма складається за набору правил (аксіом) та твредження, яке
	слід перевірити (теореми)
	Представник: Prolog (5 покоління)
 - Об'єктно-орієнтована парадигма (ООП) - базується на принципах взаємодії
	Розроблялась як засіб описання еволюційних систем, у яких задаються
	об'єкти тп правила їх взаємодії. Суть програми - еволюція систем об'єктів.
	З точки зору практичного програмування вносить ідею колекцій - як 
	розвиток поняття масиву, але з можливістю змін розміру (через еволюцію - 
	роботу програми)
	Представники ООП: C#, Java, JavaScript, Python, PHP
*/
#include <iostream>
#include <memory>
#include <conio.h>
#include "basics.h"

void basics() {
	std::cout << "OOP Basics" << std::endl;
	//LinkedList<Product*> stock;                   // Перелік покажчиків (stock - статичний об'єкт LinkedList, який вже є)
		// + автоматично знищиться після завершення ф-ції basics() 
		// - весь об'єкт stock розміщується у стеку

		// LinkedList<Product*>* stock;					 // Покажчик на перелік покажчиків (stock - покажчик на об'єкт LinkedList, якого ще немає)
		// + економія стекової пам'яті, у стеку тільки адреса
		// - необхідно створити об'єкт: stock = new LinkedList<Product*>();
		//   та не забути видалити (delete stock), оскільки автоматично звільниться 
		//   тільки адреса, а не об'єкт за нею

		// LinkedList<std::unique_ptr<Product>> stock;	 // Перелік розумних покажчиків
	

	//std::unique_ptr<LinkedList<Product*>> stock = 	    // Розумний покажчик на перелік
		//std::make_unique<LinkedList<Product*>>();  // thisisithiithisihrihsithitsdhi
	// оптимальний варіант - покажчик в середині розумного покажчика та
	// автоматичне видалення після роботи
	      
	LinkedList<Product*> stock;// = new LinkedList<Product*>();

	int N = 0;


	#pragma region Laptops
	stock.add((new Laptop())
		->setHardware("Intel Core 5, RAM 16GB, SSD 512GB")
		->setPower(90)
		->setName("Acer Nitro")
		->setPrice(60499)
	);   
	N++;
	#pragma endregion Laptops

	#pragma region Monitors

	//stock.add((new Monitor())
	//	->setDiagonal(32)
	//	->setPower(120)
	//	->setName("Dell Vision")
	//	->setPrice(7950)
	//); 
	//N++;

	stock.add((new Monitor())
		->setDiagonal(27)
		->setPower(35)
		->setName("Xiaomi G Pro 27Qi")
		->setPrice(15034)
	); 
	N++;

	stock.add((new Monitor())
		->setDiagonal(27)
		->setPower(37)
		->setName("ASUS TUF Gaming VG27AQ5A")
		->setPrice(10463)
	); 
	N++;

	stock.add((new Monitor())
		->setDiagonal(34)
		->setPower(40)
		->setName("MSI MAG 341CQP QD-OLED")
		->setPrice(46099)
	); 
	N++;

	stock.add((new Monitor())
		->setDiagonal(27)
		->setPower(38)
		->setName("GIGABYTE MO27Q28GR")
		->setPrice(33899)
	); 
	N++;

	#pragma endregion Monitors

	#pragma region Mouses
	stock.add((new Mouse())
		->setDpi(1200)
		->setConnection("USB")
		->setName("Razor 1")
		->setPrice(12345)
	);  
	N++;
	stock.add((new Mouse())
		->setDpi(1200)
		->setConnection("USB")
		->setName("Razor 2")
		->setPrice(67890)
	);  
	N++;
	#pragma endregion Mouses

	#pragma region Keyboards
	stock.add((new Keyboard())
		->setType("Mechanical")
		->setConnection("USB")
		->setName("Vinga")
		->setPrice(54321)
	);  
	N++;
	#pragma endregion Keyboards

	//std::cout << "Stock has " << N << " products. Select an action:" << std::endl
	//	<< "1. Show all" << std::endl
	//	<< "2. Find by name" << std::endl
	//	<< "3. Find by price" << std::endl
	//	<< "0. Exit" << std::endl;
	int choice;
	int counter = 0;
	//choice = _getch();

	//if (choice == 0 || choice == 224) choice = _getch();
	std::string line;
	do {
		std::cout << std::endl << std::endl
			<< " -== Product Menu ==-" << std::endl
			<< "Stock has " << N << " products. Select an action:" << std::endl
			<< "1. Show all" << std::endl
			<< "2. Find by name" << std::endl
			<< "3. Find by price" << std::endl
			<< "4. Sort by ascending price" << std::endl
			<< "5. Sort by descending price" << std::endl
			<< "0. Exit" << std::endl;
		choice = _getch();
		switch (choice) {
		case '1':
			std::cout << std::endl;
			for (int i = 0; i < N; ++i) {
				Product* p = stock[i];
				std::cout << p << std::endl;
			}
			break;
		case '2':
			std::cout << std::endl << "Search by name: ";
			std::getline(std::cin, line);
			//int counter = 0;
			std::cout << std::endl;
			// geeksforgeeks code
			for (auto& ch : line) {
				ch = tolower(ch);
			}

			for (int i = 0; i < N; ++i) {
				std::string p = stock[i]->getName();
				for (auto& ch : p) {
					ch = tolower(ch);
				}
				if (!p.find(line)) {
					std::cout << stock[i]->getName() << " ( " << stock[i] << " )" << std::endl;
					counter++;
				}
			}
			if (counter > 0) {
				std::cout << "Found " << counter << " product(s)" << std::endl;
			}
			else if (counter == 0) {
				std::cout << "Couldn't find a product by that name" << std::endl;
			}
			break;
		case '3':
			double currentMax, currentMin, maxPrice, minPrice;
			currentMax = currentMin = stock[0]->getPrice();
			for (int i = 0; i < N; ++i) {
				double p = stock[i]->getPrice();
				if (currentMax <= p) { currentMax = p; }
				if (currentMin >= p) { currentMin = p; }
			}

			std::cout << std::endl << "Enter min price(> " << currentMin << " ): ";
			std::cin >> minPrice;
			std::cout << std::endl << "Enter max price(< " << currentMax << " ):";
			std::cin >> maxPrice;

			if (minPrice > maxPrice) { 
				std::cout << "Range set incorrectly, maybe you meant " << maxPrice << "-" << minPrice << std::endl;
				std::swap(minPrice, maxPrice); 
			}

			std::cout << std::endl;
			for (int i = 0; i < N; ++i) {
				double p = stock[i]->getPrice();
				if (p >= minPrice && p <= maxPrice) {
					std::cout << stock[i] << std::endl;
					counter++;
				}
			}
			if (counter > 0) {
				std::cout << "Found " << counter << " product(s)" << std::endl;
			}
			else if (counter == 0) {
				std::cout << "Couldn't find a product in that price range" << std::endl;
			}
			break;
		case '4':
			bool swap;
			do {
				swap = false;
				for (int i = 0; i < N-1;++i) {
					if (stock[i]->getPrice() >= stock[i + 1]->getPrice()) {
						std::swap(stock[i], stock[i + 1]);
						swap = true;
					}
				}
			} while (swap);
			for (int i = 0; i < N; ++i) {
				Product* p = stock[i];
				std::cout << p << std::endl;
			}
			break;
		case '5':
			do {
				swap = false;
				for (int i = 0; i < N-1;++i) {
					if (stock[i]->getPrice() <= stock[i + 1]->getPrice()) {
						std::swap(stock[i], stock[i + 1]);
						swap = true;
					}
				}
			} while (swap);
			for (int i = 0; i < N; ++i) {
				Product* p = stock[i];
				std::cout << p << std::endl;
			}
			break;
		case '0': break;
		default:
			std::cout << "Wrong choice" << std::endl;
			break;
		}
	} while (choice != '0');
	
	//stock.print();

	//delete stock;
}
/*
void basics2() {
	std::cout << "OOP Basics" << std::endl;
	// Поліморфізм - поєднання до єдиного масиву (колекції)
	// об'єктів різного типу. Формально, об'єкти мають один
	// тип (базового класу), при цьому фактично є об'єктами
	// похідних (дочірніх) типів

	Product* stock[2];

	stock[0] = (new Laptop())
		->setHardware("Intel Core 5, RAM 16GB, SSD 512GB")
		->setPower(90)
		->setName("Acer Nitro")
		->setPrice(60499);

	stock[1] = (new Monitor())
		->setDiagonal(32)
		->setPower(120)
		->setName("Dell Vision")
		->setPrice(7950);

	std::unique_ptr<Product> ptr = std::make_unique<Laptop>( (new Laptop())
		->setHardware("Intel Core 5, RAM 16GB, SSD 512GB")
		->setPower(90)
		->setName("Acer Nitro")
		->setPrice(60499)
	);

	 //std::unique_ptr<Product> ptr2 = ptr; - помилка, не можна зробити другий
	//                                         покажчик на один об'єкт

	std::unique_ptr<Product> ptr2 = std::move(ptr);

	std::shared_ptr<Product> s1 = std::make_shared<Monitor>((new Monitor())
		->setDiagonal(32)
		->setPower(120)
		->setName("Dell Vision")
		->setPrice(7950)
	);

	std::shared_ptr<Product> s2 = s1;

	for (auto product : stock) {
		std::cout << product->toString() << std::endl;
	}

//	Site* available[2];
//
//	available[0] = (new Flat())
//		->setRoom(123)
//		->setSquare(456)
//		->setLocation("City")
//		->setPrice(789)
//		->setName("Flat1");
//
//	available[1] = (new Car())
//		->setGas("Diesel")
//		->setGear("Manual")
//		->setYear(2026)
//		->setPrice(123123)
//		->setName("Car1");
//
//	for (auto site : available) {
//		std::cout << site->toString() << std::endl;
//	}
}
*/
/*
Основні принципи ООП.
Абстрагування, спадкування, поліморфізм, інкапсуляція.

Абстракція - термін, що означає поєднання деякої множини сутностей.
Приклад - природна мова. Майже будь-яке слово значить множину.
"Телефон" - величезна множина реальних речей (сутностей).
Машинним мовам абстракція не властива, інструкції мають чітке вираження.
Абстрагування - побудова мовних конструкцій, здатних поєднувати
множинні властивості (сутності та інші абстракції).

Створення абстракцій передбачає вивчення (аналіз) предметної області
(чому присвячена програма). Наприклад, крамниця. Виписуємо усі товари,
що мають бути в крамниці, з усіма їх важливими характеристиками.

Ноутбук              Монітор            Миша              Клавіатура
 - назва              - назва            - назва           - назва
 - ціна               - ціна             - ціна            - ціна
 - "залізо"           - діагональ        - DPI             - тип
 - потужність         - потужність       - підключення     - підключення

1) Знаходимо, що є спільного у ВСІХ сутностей: назва та ціна
формуєму вищу абстракію: товар (Product), що поєднує все, що в нас є
						  Product
						  - назва    -- інкапсуляція - переміщення спільних
						  - ціна        властивостей до абстрацій
		  /           /              \                \
Ноутбук              Монітор            Миша              Клавіатура
 - "залізо"           - діагональ        - DPI             - тип
 - потужність         - потужність       - підключення     - підключення

2) Знаходимо групи зі спільними властивостями і будуємо наступний рівень
абстракцій:
 Електротовари (-потужність)     Периферія (-підключення)

						  Product
						- назва - ціна
					  /                \
			Електротовари             Периферія
			- потужність              - підключення
			/         \               /            \
		Ноутбук      Монітор         Миша        Клавіатура
		- "залізо"   - діагональ     - DPI       - тип

повторюємо п.2) для всіх можливих групувань
----------------
Спадкування - механізм реалізації абстрагування - створення класів на
базі інших класів з їх розширенням. Дочірній клас (нащадок) повністю
включає в себе батьківський клас і може додавати власні елементи.
Спадкування може бути каскадним, тобто Електротовари спадкуються від Товару,
а Ноутбук - від Електротовару (а значить і від Товару). Але на відміну
від простого розширення, спадкування зберігає типізацію, тобто
Ноутбук окрім того, що сам є типом, також є типом Електротовар і Товар.

Д.З. Обрати предметну галузь для програмування (взяти з прикладів
популярних сайтів - форуми, оренда житла/автівок тощо)
Виписати основні сутності, провести абстрагування - побудувати
ієрархію класів з абстракціями. Основний результат - діаграма класів.
-----------------
Віртуальні методи
Різниця між віртуальними та невіртуальними методами виникає коли тип
даних посилання на об'єкт та тип самого об'єкта не є однаковими.
(посилання через батьківський тип)
Electrical* stock = new Laptop()
тип посилання (stock) - Electrical*
тип об'єкту - Laptop*
Віртуальні методи викликаються у об'єкта
  stock->v() -- Laptop::v
Невіртуальні методи - за типом даних
  stock->nv() -- Electrical::nv
Невіртуальні методи створюються за замовчанням,
для створення віртуальних необхідно додати оператор "virtual"
*/

/*
"Розумні Покажчики" (Smart Pointers) - спеціальні конструкції, які
дозволяють автоматично контралювати знищення об'єктів. Їх можна розуміти
як "оболонки" над об'єктами, які не змінюють правила роботи з ними, але
додають спостереження за їх використанням: 
	якщо об'єкт перестає використовуватись,
	він знищується.

unique_ptr - унікальний покажчик, мається на увазі, що неможна створити
другий покажчик на вже створений об'єкт. Якщо потрібно перенести посилання,
то слід скористатись std::move. Створюється командою std::make_unique
shared_ptr - розподілений покажчик, дозволяє створювати кілька посилань
на один об'єкт. Створюється командою std::make_shared

Ідея роботи в тому, що розумні покажчики насправді не є покажчиками, а є
звичайними змінними, що в середині зберігають покажчик. Змінні, що
виходят з області видності, видаляються автоматично, тоді як
виділена пам'ять (для покажчиків) закріплюється за всією програмою і не
керується при виході змінних з областей видності.
*/
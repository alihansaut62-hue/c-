#include <iostream>
#include <clocale>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	unsigned short number = 2; // это целочисленный тип данных, который может хранить значения от 0 до 65535
	int numbe = 40; // это целочисленный тип данных, который может хранить значения от -2147483648 до 2147483647
	//std::cout << "переменная\n\n" << UINT_MAX << std::endl;

	float nomber3 = 3.14f; // это тип данных с плавающей запятой, который может хранить десятичные числа
	double number4 = 3.14; // это тип данных с плавающей запятой, который может хранить десятичные числа с большей точностью, чем float

	char symbol = 'A'; // это тип данных для хранения одного символа
	bool isTrue = true; // это логический тип данных, который может хранить только два значения: true (истина) и false (ложь)
	std::string text = "Привет, мир!"; // это тип данных для хранения строк текста
	cont std::string text2 = "Привет, мир!"; // это константная строка, которая не может быть изменена после инициализации


	short number1, number2, res;

	std::cout << "выводите число 1\n";
	std::cin >> number1;
	std::cout << "выводите число 2\n";
	std::cin >> number2;

	res = number1 + number2;
	std::cout << "resultat сложения: " << res << std::endl;
	



	return 0;
}
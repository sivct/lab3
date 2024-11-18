#include <iostream>
#include <cmath>
#include <string>


bool CheckNat(int64_t);		//Проверка на натуральность числа.
void OutputEnterNum();		//"Введите значение n"
void InputNumber(int64_t&);		//Ввод числа.
int64_t Count_digit_of_num(int64_t);	//Колличество цифр в числе. 
int64_t MaxRepeatedDigitOfNumber(int64_t);		//Цифра, повторяющееся максимальное колличество раз в числе.
int64_t Adding_Digit_Repeated_Max_Number_Of_Times_In_Parity_Number(int64_t);	//Добовление цифры, повторяющееся максимальное колличество раз, с лева и с права.
void FriendNum(int64_t);	//Функция для нахождения дружественного числа.
void OutputEnterSection();						//"Задайте отрезок [a,b]".
void InputSection(int64_t&, int64_t&);			//Задание отрезка.
void AmstrongNums(int64_t, int64_t);			//Ф-ция для нахождения всех чисел Амстронга на нашем отрезке.
bool Number_From_Number(int64_t&, int64_t&);	//Задание No16. Определяет возможность получения числа А вычеркиванием цифр из числа В.
void InputTwoNumbers(int64_t&, int64_t&);		//Ввод двух чисел для задания No16.
void ResultNo16(int64_t, int64_t);		//Функция для определения возможности получения A из B.




int main() {
	int64_t num{ 0 }, leftboard{ 0 }, rightboard{ 0 }; int64_t numA{ 0 }, numB{ 0 };
	std::cout << "No. 3:\n";
	InputNumber(num);
	std::cout << Adding_Digit_Repeated_Max_Number_Of_Times_In_Parity_Number(num) << std::endl;
	std::cout << "No. 9:\n";
	InputNumber(num);
	FriendNum(num);
	std::cout << "No. 13:\n";
	InputSection(leftboard, rightboard);
	AmstrongNums(leftboard, rightboard);
	std::cout << "No. 16:\n";
	ResultNo16(numA, numB);
	return 0;
}


void OutputEnterNum() {
	std::cout << "Enter nat num >> ";
}
void OutputEnterSection() {
	std::cout << "Enter nat section [a, b] >> ";
}



void InputNumber(int64_t& num) {
	OutputEnterNum();
	std::cin >> num;
	if (!CheckNat(num)) {
		std::cout << "Num is not natural(((\n" << "Enter new nat num >> ";
		std::cin >> num;
	}
}
void InputSection(int64_t& leftboard, int64_t& rightboard) {
	OutputEnterSection();
	int64_t temp{ 0 };
	std::cin >> leftboard >> rightboard;
	if (leftboard > rightboard) {
		temp = leftboard;
		leftboard = rightboard;
		rightboard = temp;
	}
	std::cout << "Your section << [" << leftboard << ", " << rightboard << "]" << std::endl;
}

//Цифра, повторяющееся максимальное колличество раз в числе.
int64_t MaxRepeatedDigitOfNumber(int64_t num) {
	int64_t counter{ 0 }, temp{}, maxdigit{ 0 }, maxcounter{ 0 };
	for (size_t digit{ 0 }; digit < 10; ++digit) {
		temp = num;
		while (temp > 0) {
			if (temp % 10 == digit) {
				++counter;
			}
			temp /= 10;
		}
		if (counter > maxdigit) {
			maxdigit = digit;
			maxcounter = counter;
		}
	}
	return maxdigit;
}

//Добовление цифры, повторяющееся максимальное колличество раз, с лева и с права.
int64_t Adding_Digit_Repeated_Max_Number_Of_Times_In_Parity_Number(int64_t num) {
	int64_t result{}, digits{ Count_digit_of_num(num) }, central_digit{ MaxRepeatedDigitOfNumber(num) };
	result = num * 10 + central_digit;
	result += central_digit * pow(10, digits + 1);
	return result;
}

//Задание No9. Функция для нахождение дружественного числа.
void FriendNum(int64_t num) {
	int64_t friendnum{ 0 }, temp{ num / 2 };
	for (int64_t divisor{ 1 }; divisor <= temp; ++divisor) {
		if (num % divisor == 0) {
			friendnum += divisor;
		}
	}
	std::cout << "Friend num is << " << friendnum << std::endl;
}

//Задание No12. Функция для нахождения всеч чисел Армстронга на отрезке [a,b].
void AmstrongNums(int64_t leftboard, int64_t rightboard) {
	int64_t amstrnum{ 0 }, temp{ 0 }, count_digit_of_num{ 0 }; double sum{ 0 };
	for (int64_t num{ leftboard }; num <= rightboard; ++num) {					//Перебор всех чисел на отрезке.
		count_digit_of_num = Count_digit_of_num(num);							//Колличество цивр в числе (для возведения в степень).
		for (int64_t digit{ 1 }; digit < 10; ++digit) {							//Перебор цивр в числе.
			temp = num;
			while (temp != 0) {
				int64_t temp_digit = temp % 10;									//Число из Num.
				if (digit == temp_digit) {										//Если перебираемое цифра есть в Num,
					sum += pow(digit, count_digit_of_num);						//то к нашей сумме прибовляем эту цифру в степени Counter_digit_of_num.  
				}
				temp /= 10;
			}
		}
		if (sum == static_cast<double>(num)) {
			std::cout << num << std::endl;
		}
		sum = 0;
	}
}

//Функция для определения колличества цифр в числе.  
int64_t Count_digit_of_num(int64_t num) {	
	int64_t count_digit_of_num{ 0 };
	while (num != 0) {
		num /= 10;
		++count_digit_of_num;
	}
	return count_digit_of_num;
}

//Проверка числа на натуральность.
bool CheckNat(int64_t num) {
	return num > 0;
}

//Ввод двух чисел для задания No16.
void InputTwoNumbers(int64_t& numA, int64_t& numB) {
	std::cout << "Enter a two nums for check, 'can we get one from the other?' >> ";
	std::cin >> numA;
	if (!CheckNat(numA)) {
		std::cout << "Num is not natural(((\n" << "Enter new nat num >> ";
		std::cin >> numA;
	}
	std::cin >> numB;
	if (!CheckNat(numB)) {
		std::cout << "Num is not natural(((\n" << "Enter new nat num >> ";
		std::cin >> numB;
	}
}

//Задание No16. Определяет возможность получения числа А вычеркиванием цифр из числа В.
bool Number_From_Number(int64_t& numA, int64_t& numB) {
	InputTwoNumbers(numA, numB);
	while (numA > 0) {
		int64_t temp{ numB }, digitB{ 0 }, digitA{ numA % 10 };
		bool found = false;					//Найдена ли цифра A в B.
		temp = numB;
		while (temp > 0) {					//Перебираем все цифры числа B.
			digitB = temp % 10;
			if (digitA == digitB) {
				found = true;				//Цифра найдена
				break;						//Выходим из внутреннего цикла
			}
			temp /= 10;
		}

		if (!found) {
			return false;					//Если хотя бы одна цифра не найдена, возвращаем false.
		}
		numA /= 10;
	}

	return true;
}

//Функция для определения возможности получения A из B.
void ResultNo16(int64_t numA, int64_t numB) {
	if (Number_From_Number(numA, numB)) {
		std::cout << "Number A can be obtained from number B." << std::endl;
	}
	else {
		std::cout << "Number A can't be obtained from number B." << std::endl;
	}
}

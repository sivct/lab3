#include <iostream>
#include <cmath>



void OutputEnterNum();
void InputNumber(int32_t&);
int32_t Counter_digit_of_num(int32_t);
void FriendNum(int32_t);
void OutputEnterSection();
void InputSection(int32_t&, int32_t&);
void AmstrongNums(int32_t, int32_t);



int main() {
	int32_t num{ 0 }, leftboard{ 0 }, rightboard{ 0 };
	InputNumber(num);
	FriendNum(num);
	InputSection(leftboard, rightboard);
	AmstrongNums(leftboard, rightboard);
	return 0;
}


void OutputEnterNum() {
	std::cout << "Enter nat num >> ";
}
void OutputEnterSection() {
	std::cout << "Enter nat section [a, b] >> ";
}



void InputNumber(int32_t& num) {
	OutputEnterNum();
	std::cin >> num;
}
void InputSection(int32_t& leftboard, int32_t& rightboard) {
	OutputEnterSection();
	int32_t temp{ 0 };
	std::cin >> leftboard >> rightboard;
	if (leftboard > rightboard) {
		temp = leftboard;
		leftboard = rightboard;
		rightboard = temp;
	}
}



void FriendNum(int32_t num) {
	int32_t friendnum{ 0 }, temp{ num / 2 };
	for (int32_t divisor{ 1 }; divisor <= temp; ++divisor) {
		if (num % divisor == 0) {
			friendnum += divisor;
		}
	}
	std::cout << "Friend num is << " << friendnum << std::endl;
}
void AmstrongNums(int32_t leftboard, int32_t rightboard) {
	int32_t amstrnum{ 0 }, temp{ 0 }, count_digit_of_num{ 0 }; double sum{ 0 };
	for (int32_t num{ leftboard }; num <= rightboard; ++num) {					//Перебор всех чисел на отрезке.
		count_digit_of_num = Counter_digit_of_num(num);							//Колличество цивр в числе (для возведения в степень).
		for (int32_t digit{ 1 }; digit < 10; ++digit) {							//Перебор цивр в числе.
			temp = num;
			while (temp != 0) {
				int32_t temp_digit = temp % 10;
				if (digit == temp_digit) {
					sum += pow(digit, count_digit_of_num);
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


int32_t Counter_digit_of_num(int32_t num) {
	int32_t count_digit_of_num{ 0 };
	while (!(num == 0)) {
		num /= 10;
		++count_digit_of_num;
	}
	return count_digit_of_num;
}

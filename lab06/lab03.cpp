/*
(실습3)연산자 오버로딩을 활용하여 아래 코드를 완성하세요. (operator+ 를 구현해야함)
예상 결과는 아래와 같아야 한다.


--예상 출력 결과--
Name is Nabi
Name is Jindo
Name is JindoNabi
Name is Jindo
---------------- -
*/

#include <iostream>

class Animal {
private:
	std::string name;

public:
	Animal() {};
	Animal(std::string name) : name(name) {};
	//Animal(std::string name) : name()

	void showName() {
		std::cout << "Name is " << name << std::endl;
	}

	Animal operator+(const Animal& a) {
		Animal test;
		test.name = name + a.name; //dog가 앞, cat이 뒤에
		return test;
	}

	//operator+ 추가하세요

};

int main() {

	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();

	Animal catDog = dog + cat; //개냥이 합성, 클래스간의 더하기를 할 때 operator가 사용되어짐
	catDog.showName();

	dog.showName();

	getchar();

	return 0;
}

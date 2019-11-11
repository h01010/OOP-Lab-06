/*
(실습 4) 아래 코드를 실행해 보세요.그리고 실습3과 다른 결과가 출력된 이유에 대해 생각해 보세요.
*/
#include <string>
#include <iostream>

class Animal {
private:
	std::string name;

public:
	Animal() {};
	Animal(std::string name) : name(name) {};

	void showName() {
		std::cout << "Name is " << name << std::endl;
	}

	Animal & operator+(const Animal &a) {
		name += a.name;	//처음 b에 넣어줌
		return *this;	//현재의 주솟값을 넘겨줌
	}
};

int main() {

	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();

	Animal catDog = dog + cat;
	catDog.showName();
	dog.showName();

	getchar();

	return 0;
}

/*
(�ǽ�3)������ �����ε��� Ȱ���Ͽ� �Ʒ� �ڵ带 �ϼ��ϼ���. (operator+ �� �����ؾ���)
���� ����� �Ʒ��� ���ƾ� �Ѵ�.


--���� ��� ���--
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
		test.name = name + a.name; //dog�� ��, cat�� �ڿ�
		return test;
	}

	//operator+ �߰��ϼ���

};

int main() {

	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();

	Animal catDog = dog + cat; //������ �ռ�, Ŭ�������� ���ϱ⸦ �� �� operator�� ���Ǿ���
	catDog.showName();

	dog.showName();

	getchar();

	return 0;
}

/*
(실습 2)  아래 프로그램은 main 함수에서 고양이 cat1 오브젝트를 생성한 후에 eat()를 호출할 경우,
eat()의 인자로 전달된 값만큼 cat1.weight 값이 증가하는 프로그램이다.
예상되는 결과값은 아래와 같다. eat 함수를 추가하여 프로그램을 완성하세요.
(힌트, this키워드와 레퍼런스 사용)

----예상 결과값---
 Weight : 10
 Weight : 14
 Weight : 18
 Weight : 33
------------------------

*/
#include<iostream>

class My_cat {
	char *name;
	int weight;


public:
	My_cat();
	My_cat(const char *name);
	My_cat(const My_cat &cat);
	~My_cat();
	My_cat& eat(int food);

	//eat 함수 선언하시오

	void show_status() const;
};

My_cat::My_cat() :name(NULL), weight(10) { }

My_cat::My_cat(const char *cat_name) : weight(10) {
	name = new char[strlen(cat_name) + 1];
	strcpy(name, cat_name);
}

My_cat::My_cat(const My_cat &cat) : weight(10) { //Copy constructor
	std::cout << "Copy constructor invocation ! " << std::endl;
	name = new char[strlen(cat.name) + 1];
	strcpy(name, cat.name);
}

My_cat::~My_cat() {		//Destructor
	if (name) delete[] name;
}

//eat 함수를 구현하세요.
My_cat& My_cat::eat(int food){
	this->weight += food;
	return *this;//객체에 대한 주솟값, 근데 그냥 반환하면 새로운 객체를 만들어서 반환, 그러므로 이전의 cat1이 아님
}
void My_cat::show_status() const {
	std::cout << " Weight : " << weight << std::endl;
}
int main() {
	My_cat cat1("Nabi");	//Cat 1 생성
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.eat(4).eat(5).eat(6); //hint: 이런 형태의 연산 지원을 위해서는 this 키워드와 레퍼런스 활용이 요구됨
	//4까지 하면 되지만, return this면 새로운 객체가 만들어져서 생성되기에 10으로 초기화된 값 +5
	//레퍼런스가 없으면 다르게 결과가 나옴
	cat1.show_status();

	getchar();
	return 0;
}

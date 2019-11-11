/*
(�ǽ� 2)  �Ʒ� ���α׷��� main �Լ����� ����� cat1 ������Ʈ�� ������ �Ŀ� eat()�� ȣ���� ���,
eat()�� ���ڷ� ���޵� ����ŭ cat1.weight ���� �����ϴ� ���α׷��̴�.
����Ǵ� ������� �Ʒ��� ����. eat �Լ��� �߰��Ͽ� ���α׷��� �ϼ��ϼ���.
(��Ʈ, thisŰ����� ���۷��� ���)

----���� �����---
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

	//eat �Լ� �����Ͻÿ�

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

//eat �Լ��� �����ϼ���.
My_cat& My_cat::eat(int food){
	this->weight += food;
	return *this;//��ü�� ���� �ּڰ�, �ٵ� �׳� ��ȯ�ϸ� ���ο� ��ü�� ���� ��ȯ, �׷��Ƿ� ������ cat1�� �ƴ�
}
void My_cat::show_status() const {
	std::cout << " Weight : " << weight << std::endl;
}
int main() {
	My_cat cat1("Nabi");	//Cat 1 ����
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.eat(4).eat(5).eat(6); //hint: �̷� ������ ���� ������ ���ؼ��� this Ű����� ���۷��� Ȱ���� �䱸��
	//4���� �ϸ� ������, return this�� ���ο� ��ü�� ��������� �����Ǳ⿡ 10���� �ʱ�ȭ�� �� +5
	//���۷����� ������ �ٸ��� ����� ����
	cat1.show_status();

	getchar();
	return 0;
}

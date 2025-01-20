#include <iomanip>
#include <iostream>
#include <Windows.h>
using namespace std;


//нелзя создать объект абстрактный класс

class A // базовый класс абстрактный класс
{
public:
	int age;
	string name;
	A(int _age, string _name) : age(_age), name(_name) { cout << "Constraction A" << endl; }
	/*void Print()
	{age << "  " << name << endl;
		cout <<
	}*/
	virtual void Print() = 0; //чисто виртуальный метод
	void f1() { cout << "@@@@@@@@@@@@@@@@@@" << endl; }
};
class B : public A
{
public:
	string group;
	B(int _age, string _name, string _group) : A(_age, _name), group(_group) {}
	void Print()
	{
		cout << age << "  " << name << "  " << group << endl;
	}
};
class C : public A
{
public:
	double salary;
	C(int _age, string _name, double _salary) : A(_age, _name), salary(_salary) {}
	void Print()
	{
		cout << age << "  " << name << " " << salary << endl;
	}
};
void main()
{
	//A obj_a(25, "Petr"); //нельзя создать объект
	//obj_a.Print();
	cout << "+++++++++++++++++++++++++++" << endl;

	B obj_b(30, "Ivan", "P317");
	obj_b.Print();
	obj_b.f1();
	cout << "+++++++++++++++++++++++++++" << endl;

	C obj_c(18, "Oleg", 2000);
	obj_c.Print();
	obj_c.f1();
	cout << "+++++++++++++++++++++++++++" << endl;

	A* a[2] = { new B(30, "Ivan", "P317"),new C(18, "Oleg", 2000) };
	for (int i = 0; i < 3; i++) {
		a[i]->Print();
	}
}
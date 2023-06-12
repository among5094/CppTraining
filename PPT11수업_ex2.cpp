#include <iostream>
#include <string>
using namespace std;

//Circle 생성자
class Circle {
	int radius;
public:
	Circle(int radius = 0) {
		this->radius = radius;
	}
	
	//radius는 private라서 외부에서 접근할 수 없다.
	//그래서 외부에서 radius를 쓸 수 있게 getRadius함수를 따로 선언해준 것이다.
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

//Circle을 상속받는 NamedCircle
class NamedCircle :public Circle {
	string name;
public:
	NamedCircle(int radius, string name);
	void show();
};

//NamedCircle 구현부
NamedCircle::NamedCircle(int radius, string name):Circle(radius) {
	this->name = name;
}
void NamedCircle::show() {
	cout << "반지름이 " << getRadius() << "인" << name << endl;
}

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
}
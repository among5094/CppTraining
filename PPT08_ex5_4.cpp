#include <iostream>
using namespace std;

//예제5-4
//목적: 객체에 대한 참조

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }

};

int main() {

	Circle circle; //객체
	Circle& refc = circle; //별명
	refc.setRadius(10);
	cout << refc.getArea() << " " << circle.getArea() << endl;  //객체든 별명이든 도 후촐은 동일 객체에 대한 호출
}
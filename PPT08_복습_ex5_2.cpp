#include <iostream>
using namespace std;

//예제5-2
//목적: 객체 리턴

class Circle {
	int radius; //디폴트 접근 지정자 -> private
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) {this->radius = radius;}
	double getArea() { return 3.14 * radius * radius; }
	
};

Circle getCircle() {
	Circle tmp(30); 
	return tmp; // tmp객체의 "복사본"을 리턴한다. 
}

int main() {
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle(); //호출되어서 getCircle로 간다음에 tmp객체의 복사본이 넘어온다.
	cout << c.getArea() << endl;
}
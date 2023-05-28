#include <iostream>
using namespace std;

//예제5_6
//목적: 참조에 의한 호출

/*
'주소에 의한 호출'로 객체를 전달하면
	1. 원본 객체를 복사하는 시간 소모가 없으며
	2. 생성자 소멸자의 비대칭 문제도 없다
	그러나 원본 객체를 훼손할 가능성이 있다 -> 개발자의 책임감이 늘어남
*/

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();

	//함수
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) {
		this->radius = radius;//this란? 객체 자신에 대한 포인터 
		//생성자의 radius = 매개변수의 radius
	}
};

//생성자 구현부
Circle::Circle() {
	radius = 1;
	cout << "생성자의 실행 radius = " << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}


void increase(Circle &c) {//c는 참조 매개 변수
	int r = c.getRadius(); //참조에 의한 호출은 ->가 아니고 .으로 접근한다. 
	c.setRadius(r + 1);
}

int main() {
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}

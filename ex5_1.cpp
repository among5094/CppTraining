#include <iostream>
using namespace std;

//예제5-1
//목적: 값에 의한 호출을 했을 때 매개 변수의 생성자는 실행되지 않는 비대칭 구조를 보기 위해서 

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

void increase(Circle c) {//3. 여기의 Circle c로 복사됨, 근데 객체c의 생성자는 실행x
	int r = c.getRadius();
	c.setRadius(r + 1);
}//4. 객체 c의 소멸자는 실행됨!! -> 생성자와 소멸자의 비대칭 구조의 실행결과

int main() {
	Circle waffle(30); //1. 객체 이름만 사용하고, 공간이 stack에 할당됨
	increase(waffle);// 2. waffle의 내용이 
	cout << waffle.getRadius() << endl;
}
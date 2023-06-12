#include <iostream>
#include <string>
using namespace std;

//Point 클래스
class Point {
protected:
	int x, y; 
public:
	void set(int x, int y);
	void showPoint();
};

//Circle생성자에 있는 멤버 함수 set 구현
void Point::set(int x, int y) {
	this->x = x; //매개변수x를 생성자의 x로 초기화
	this->y = y; //매개변수y를 생성자의 y로 초기화
}

//Circle생성자에 있는 멤버 함수 showPoint 구현
void Point::showPoint() {
	cout << "(" << x << "," << y << ")" << endl;
}

//-------------------------------------------------//

//public권한으로 Point클래스를 상속받는 클래스 ColorPoint  
class ColorPoint :public Point {
	string color; //private임
public:
	void setColor(string color);
	void showColorPoint();
	bool equals(ColorPoint p);
};

//ColorPoint 클래스의 멤버 함수 setColor 구현
void ColorPoint::setColor(string color) {
	this->color = color; //매개변수 color을 필드의 color로 초기화
}

//ColorPoint 클래스의 멤버 함수 showColorPoint 구현
void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint(); //Point클래스(상위 클래스, super 클래스)의 showPoint()호출
}

//ColorPoint 클래스의 멤버 함수 equals 구현
bool ColorPoint::equals(ColorPoint p) {
	//Point x,y가 proteced 접근이기 때문에 하위 클래스 ColorPoint에서도 접근할 수 있다.
	if (x == p.x && y == p.y && color == p.color)
		return true;
	else
		return false;
}

int main() {

	Point p; // 기본 클래스 객체 생성
	p.set(2, 3); //
	p.x = 5;
	p.y = 5;
	p.showPoint();

	ColorPoint cp; //파생 클래스의 객체 생성
	cp.x = 10;
	cp.y = 10;
	cp.set(3, 4); 
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ? "True" : "False");

}
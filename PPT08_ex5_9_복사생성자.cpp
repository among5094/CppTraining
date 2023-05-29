#include <iostream>
using namespace std;

//예제 5_9: 복사생성자

class Circle {
private:
	int radius; //디폴트 접근 지정자 -> private
public:
	Circle(const Circle& c); //복사생성자 선언
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

//복사생성자 구현부
Circle::Circle(const Circle& c) {
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius = " << radius << endl;
}

int main() {

	Circle src(30); //src객체의 인자가 1개인 생성자 호출
	Circle dest(src); //dest객체의 복사 생성자 호출, dest객체 공간 할당

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}

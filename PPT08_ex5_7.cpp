#include <iostream>
using namespace std;

//예제5_7
//목적: 키보드로부터 반지름 값을 읽어 Circle객체에 반지름을 설정하는 readRadius()함수 작성해보기

class Circle {
	int radius; //디폴트 접근 지정자 -> private
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void readRadius(Circle &ref) {
	int radius;
	cout << "반지름을 입력하세요>> ";
	cin >> radius;
	ref.setRadius(radius); //객체 c의 반지름 설정
}

int main() {
	Circle donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}
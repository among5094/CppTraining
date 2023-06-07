#include <iostream>
using namespace std;

//예제7_8 : 전위 ++연산자 작성
//Power객체를 1증가시키는 전위 ++연산자를 Power 클래스의 operator++() 멤버 함수로 작성

class Power {
private:
	int kick;
	int punch;

public:
	//멤버 변수로 초기화 해주는 매개변수가 2개인 생성자 
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; //this: 객체 a 자신에 대한 포인터
		this->punch = punch;
	}
	void show(); //cout을 정의할 show 함수
	
	Power& operator++(); //전위 ++연산자 함수 선언

};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

//전위++ 연산자 멤버 함수 구현
Power& Power::operator++() {

	this->kick++; //자신의 kick과 punch를 각각 증가시킨 후에
	this->punch++;
	return *this; //변경된 객체 자신(객체 a)의 참조 리턴
}

int main() {

	Power a(3, 5), b;

	cout << "전위 연산자 이용 전 " << endl;
	a.show();
	b.show();

	b = ++a;//전위 ++ 연산자 사용

	cout << "전위 연산자 이용 후 " << endl;
	a.show();
	b.show();

}

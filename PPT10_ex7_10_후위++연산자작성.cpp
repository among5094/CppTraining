#include <iostream>
using namespace std;

//예제7_10 : 후위 연산자 구현

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

	Power operator++(int x); ////후위 ++연산자 함수 선언
	//전위 연산자와 후위 연산자를 구분하기 위해 의미 없는 값x를 두도록하자
	//전위 연산자는 이렇게 생겨서 구분이 안 감.. bool operator++();

};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

//후위 ++연산자 함수 구현
Power Power::operator++ (int x) {

	Power tmp = *this; //증가 이전 객체 상태를 저장, tmp는 임시 객체임
	kick++;
	punch++;
	return tmp; //증가 이전 객체(객체 a) 리턴
}

int main() {

	Power a(3, 5), b;
	cout << "후위 연산자 이용 전 " << endl;
	a.show();
	b.show();

	b = a++; //operator++ (int) 함수 호출
	cout << "후위 연산자 이용 후 " << endl;
	a.show();
	b.show();

}
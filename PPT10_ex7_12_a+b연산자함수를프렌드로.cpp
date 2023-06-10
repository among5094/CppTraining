#include <iostream>
using namespace std;

//예제7_12 : a+b를 위한 연산자 함수 정의하는 법 -> friend로 작성

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
	friend Power operator+(int op1, Power op2); //프렌드 선언

};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

//외부 함수로 구현된 연산자 함수
Power operator+(int op1, Power op2) {
	Power tmp; //임시 객체 생성
	tmp.kick = op1 + op2.kick;//kick 더하기
	tmp.punch = op1 + op2.punch;//punch 더하기
	return tmp; //임시 객체 리턴
}

int main() {

	Power a(3, 5), b;

	cout << " 2+a 전 " << endl;
	a.show();
	b.show();

	b = 2 + a;
	cout << " 2+a 후 " << endl;
	a.show();
	b.show();

}
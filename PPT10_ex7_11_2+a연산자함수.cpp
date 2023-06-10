#include <iostream>
using namespace std;

//예제7_11 : 2+a를 위한 연산자 함수 정의하는 법 -> friend로 작성
/*
설명:
첫 번째 피연산자가 객체가 아닌 경우(정수2임), Power클래스의 "외부 함수"로 밖에 구현할 수 없다. 
즉, 연산자 함수를 오직 외부 연산자로만 작성해야 한다.

그러나 외부 연산자 함수로 선언하면, Power의 private멤버에 접근할 수 없고
public으로 선언하면 캡슐화의 원칙이 깨지기 때문에 그것도 안된다.

그래서 이것을 friend 함수 선언으로 해결함. Power클래스에 프렌드로 초대하는 것이다.

*/
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

	b = 2+a;
	cout << " 2+a 후 " << endl;
	a.show();
	b.show();

}
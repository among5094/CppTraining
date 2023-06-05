#include <iostream>
using namespace std;

//예제7_5 : 두 개의 객체를 비교하는 == 비교연산자 작성

/* Power에 대한 설명 : Power는 게임에서 인물이나 기계의 에너지(파워)를 표현한 것으로,
발로 차는 힘 kick과 주먹으로 때리는 힘 punch 두 멤버 변수를 모델링 한 것. */

// 연산자 함수(==)의 기능에 대한 설명: 두 피연산자의 kick과 punch가 같으면 true출력, 아니면 false출력 -> 
//그러므로 함수의 리턴타입은 bool이여야 한다


class Power {
private:
	int kick; //발로 차는 힘
	int punch; //주먹으로 치는 힘

public:
	//멤버 변수로 초기화 해주는 매개변수가 2개인 생성자 
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; //this: 객체 a 자신에 대한 포인터
		this->punch = punch;
	}

	void show(); //cout을 정의할 함수

	bool operator ==(Power op2); // ==연산자 함수 선언

};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

// +연산자 멤버 함수 구현
bool Power::operator== (Power op2) {
	if (this->kick == op2.kick && this->punch == op2.punch)
		return true;
	else
		return false;
}

int main() {

	Power a(3, 5), b(4, 5);// 2개의 객체 생성
	a.show();
	b.show();

	if (a == b)
		cout << "두 파워가 같습니다. " << endl;
	else 
		cout << "두 파워가 같지 않습니다. " << endl;

}


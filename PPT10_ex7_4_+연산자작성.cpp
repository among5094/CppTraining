#include <iostream>
using namespace std;

//예제7_4 : 두 개의 power 객체를 더하는 + 연산자를 Power 클래스의 Operator+() 멤버함수로 작성

/* Power에 대한 설명 : Power는 게임에서 인물이나 기계의 에너지(파워)를 표현한 것으로, 
발로 차는 힘 kick과 주먹으로 때리는 힘 punch 두 멤버 변수를 모델링 한 것. */

class Power {
	int kick; //발로 차는 힘
	int punch; //주먹으로 치는 힘

public:
	//멤버 변수로 초기화 해주는 매개변수가 2개인 생성자 
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; //this: 객체 a 자신에 대한 포인터
		this->punch = punch;
	}

	void show(); //cout을 정의할 함수


	//+연산자 함수 선언
	Power operator+ (Power op2); 
	//Power operator+ (Power& op2); 이렇게 써도 됨
	//Power는 호출되는 첫 번째 매개변수, op2는 두 번째 매개변수(맴버함수라서 객체를 통해서만 호출됨)

};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

// +연산자 멤버 함수 구현
Power Power::operator+ (Power op2) {

	Power tmp; //임시 객체 생성
	tmp.kick = this->kick + op2.kick; //kick 더하기
	tmp.punch = this->punch + op2.punch; //punch 더하기
	return tmp; //더한 결과 리턴

}

int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b; //파워 객체 +연산
	//만약 c=b+a라면 결과가 같아서 같아보여도 다른거임, 이 연산은 객체b 호출함

	a.show(); //a의 kick과 punch출력
	b.show(); //b의 kick과 punch출력
	c.show(); //객체 a와 b의 kick의 덧셈과 객체 a와 b의 punch의 덧셈 출력함

}
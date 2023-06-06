#include <iostream>
using namespace std;

//예제7_6 : 두 개의 power 객체를 더하는 += 연산자 작성

//Power에 대한 설명 : Power는 게임에서 인물이나 기계의 에너지(파워)를 표현한 것으로,
//발로 차는 힘 kick과 주먹으로 때리는 힘 punch 두 멤버 변수를 모델링 한 것.

// += 연산자 함수의 기능에 대한 설명: 객체 a와 b를 합쳐 a를 새로운 파워로 갱신하는 것으로 정의한다.

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
	void show(); //cout을 정의할 show 함수
	
	Power& operator+= (Power op2); //+=연산자 함수 선언
	//참조 타입인 이유?: 
};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

// +연산자 멤버 함수 구현
Power& Power::operator+= (Power op2) {
	kick = this->kick + op2.kick; //a의 kick에 b의 kick을 더함
	punch = this->punch + op2.punch; //a의 punch에 b의punch를 더함
	return *this; //합한 결과 리턴
	//리턴 타입이 Power& 이므로 객체 자신의 참조가 리턴됨
}

int main() {

	Power a(3, 5), b(4, 6), c;//객체 생성
	
	cout << "갱신 전" << endl;
	cout << "a출력 ";
	a.show();
	cout << "b출력 ";
	b.show();

	c = a += b; //파워 객체 더하기. operator+=() 멤버 함수 호출

	cout << "갱신 후" << endl;
	cout << "a출력 ";
	a.show();
	cout << "c출력 ";
	c.show();

}

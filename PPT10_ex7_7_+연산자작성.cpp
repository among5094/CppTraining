#include <iostream>
using namespace std;

//예제7_7 :Power객체에 정수를 더하는 +연산자를 Power클래스의 operator+(int) 멤버 함수로 정의

//Power에 대한 설명 : Power는 게임에서 인물이나 기계의 에너지(파워)를 표현한 것으로,
//발로 차는 힘 kick과 주먹으로 때리는 힘 punch 두 멤버 변수를 모델링 한 것.

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
	Power operator+ (int op2); //operator+ (int op2)함수는 더한 결과로 Power객체를 리턴한다.
};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

//operator+ (int op2) 정의
Power Power::operator+ (int op2) {
	
	Power tmp; //임시 객체 생성
	tmp.kick = this->kick + op2;// kick에 op2더하기 
	tmp.punch = this->punch + op2;// kick에 op2더하기 
	return tmp; //임시 객체 리턴
}

int main() {

	Power a(3, 5), b;

	cout << "더하기 전 " << endl;
	a.show();
	b.show();

	b = a + 2;
	cout << "각각 2를 더한 후 객체b 출력 " << endl;
	a.show();
	b.show();

}

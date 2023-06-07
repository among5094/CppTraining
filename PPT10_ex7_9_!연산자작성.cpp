#include <iostream>
using namespace std;

//예제7_9 : Power 클래스에 !연산자 작성
//!a는 a의 kick과 punch가 모두 0이면 true, 아니면 false리턴 -> 그렇기 때문에 bool 타입이여야됨

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

	bool operator!(); // ! 연산자 함수 선언

};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

//멤버 함수 구현
bool Power::operator!() {

	if (this->kick == 0 && this->punch == 0)
		return true;
	else
		return false;
	
}

int main() {
	
	Power a(0, 0), b(5, 5);

	if (!a)
		cout << "a의 파워가 0이다. " << endl; //!연산자 호출
	else 
		cout << "a의 파워가 0이 아니다. " << endl;

	if (!b)
		cout << "b의 파워가 0이다. " << endl; //!연산자 호출
	else
		cout << "b의 파워가 0이 아니다. " << endl;
}
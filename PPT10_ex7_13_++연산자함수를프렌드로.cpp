#include <iostream>
using namespace std;

//예제7_13 : 전위, 후위 ++연산자 함수를 프렌드로 friend로 작성

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

	//오버로딩
	friend Power& operator++(Power& op); //전위 연산자
	friend Power& operator++(Power& op, int x); //후위연산자이고 int x는 구분을 위해 의미없는 x 선언해준거임

	/* -참조 매개 변수를 사용하는 이유: 
	참조 매개 변수를 사용하지 않으면, 매개 변수 op에 객체a의 복사본이 전달되니까
	op객체의 kick과 punch값을 증가시켜도 객체 a는 변하지 않고, ++a나 ++a나는 연산 이전과 동일하게 된다. 
	그래서 Power& op의 참조 매개 변수를 사용함으로써 op는 객체a를 참조하게 되어 op객체를 변경하면
	객체a가 변경된다.
	*/

};

//출력해주는 함수 void 구현
void Power::show() {
	cout << "kick=" << kick << ',' << "punch = " << punch << endl;
}

//전위 연산자 함수 구현
Power& operator++(Power& op) {
	
	op.kick++;
	op.punch++;
	return op; 
}

//후위 연산자 함수 구현
Power& operator++(Power& op, int x) {

	Power tmp = op; //변경하기 전의 op상태 저장
	op.kick++;
	op.punch++;
	return tmp; // 변경 이전의 op 리턴
}

int main() {

	Power a(3, 5), b;

	cout << "전위 ++ 연산자" << endl;
	b = ++a;
	a.show();
	b.show();

	b = a++;
	cout << "후위 ++ 연산자" << endl;
	a.show();
	b.show();

}
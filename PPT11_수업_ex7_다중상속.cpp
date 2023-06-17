#include <iostream>
using namespace std;

class Adder {
protected: //외부접근x but 하위 클래스 접근 가능
	int add(int a, int b) { return a + b; }
};

class Subtractor {
protected: //외부접근x but 하위 클래스 접근 가능
	int minus(int a, int b) { return a - b; }
};

//다중상속
class Calculator : public Adder,public Subtractor {
public:
	int calc(char op, int a, int b);
};

//Calculator 클래스 구현부
int Calculator::calc(char op, int a, int b) {
	int res = 0;

	switch (op) {
	case'+': res = add(a, b); 
		break;
	case'-': res = minus(a, b);
		break;
	}
	return res;
};

int main() {
	Calculator handCalculator;
	cout << "2 + 4 = " << handCalculator.calc('+', 2, 4) << endl;
	cout << "100 - 8 = " << handCalculator.calc('-', 100, 8) << endl;
}

//다중상속의 문제점 -> 자바는 괜히 다중상속을 금지한 것이 아니다 
//다중 상속으로 인한 기본 클래스의 "멤버 중복" 때문!

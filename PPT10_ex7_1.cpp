#include <iostream>
using namespace std;

//예제7_1 :프렌드 선언 3종류 중 1번째
//클래스의 외부에 구현된 함수를 클래스 내에 프렌드 키워드로 선언하는 경우

class Rect; //선언만
bool equals(Rect r, Rect s); //외부에 선언만

class Rect {
	int width;
	int height;
public:
	Rect(int width, int height) {
		this->width = width; //나의 멤버 변수 초기화
		this->height = height;
	}

	friend bool equals(Rect r, Rect s);// 선언과 동시에 정의x, "얘는 내 친구야!"라는 선언만
	//여기서 만약 friend를 정의해주게 되면 멤버 함수임
};

//전역함수의 정의
bool equals(Rect r, Rect s) {

	if (r.width == s.width && r.height == s.height)//원래는 private라서 .으로 접근불가 but friend 선언 덕분에 가능함.
		return true;
	else
		return false;
}

int main() {

	Rect a(3, 4), b(4, 5); //객체 a와 b인데 생성자를 통해 선언과 동시에 초기화해줌

	if (equals(a, b))
		cout << "같음" << endl;
	else
		cout << "다름" << endl;
}


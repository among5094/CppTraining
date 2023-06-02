#include <iostream>
using namespace std;

//예제7_2 :프렌드 선언 3종류 중 2번째 : 
//다른 클래스의 멤버 함수를 클래스의 프렌드 함수로 선언

class Rect;

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) {
		this->width = width; //나의 멤버 변수 초기화
		this->height = height;
	}

	friend bool RectManager::equals(Rect r, Rect s);// 선언과 동시에 정의x, "얘는 내 친구야!"라는 선언만
	//			다른 클래스의 멤버 함수(RectManager클래스의 equals 함수) 를 프렌드함수로 선언
};

//전역함수의 정의
bool RectManager::equals(Rect r, Rect s) {

	if (r.width == s.width && r.height == s.height)//원래는 private라서 .으로 접근불가 but friend 선언 덕분에 가능함.
		return true;
	else
		return false;
}

int main() {

	RectManager man; //다른 클래스 RectManager
	Rect a(3, 4), b(4, 5); //객체 a와 b인데 생성자를 통해 선언과 동시에 초기화해줌

	if (man.equals(a, b))
		cout << "같음" << endl;
	else
		cout << "다름" << endl;
}


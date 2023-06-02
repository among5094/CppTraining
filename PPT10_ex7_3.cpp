#include <iostream>
using namespace std;

//예제7_3 :프렌드 선언 3종류 중 3번째 : 
//다른 클래스의 "모든 멤버 함수"를 클래스의 프렌드 함수로 "한 번에" 선언

class Rect;

class RectManager {//RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect { //Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) {
		this->width = width; //나의 멤버 변수 초기화
		this->height = height;
	}

	friend RectManager;// RectManager 클래스의 "모든 함수"를 프렌드 함수로 선언
	
};

//전역함수의 정의
bool RectManager::equals(Rect r, Rect s) {

	if (r.width == s.width && r.height == s.height)//원래는 private라서 .으로 접근불가 but friend 선언 덕분에 가능함.
		return true;
	else
		return false;
}

void RectManager::copy(Rect& dest, Rect& src) {

	//복사
	dest.width == src.width; 
	dest.height == src.height;

}

int main() {

	RectManager man; //다른 클래스 RectManager
	Rect a(3, 4), b(4, 5); //객체 a와 b인데 생성자를 통해 선언과 동시에 초기화해줌

	man.copy(b, a); //a를 b에 복사

	if (man.equals(a, b))
		cout << "같음" << endl;
	else
		cout << "다름" << endl;
}


#include <iostream>
#include <string>
using namespace std;

class TV {
	int size; //스크린 크기
public:
	//생성자는 물려받긴 하는데 영역이 나뉨.
	TV() { size = 20; }
	TV(int size) { this->size = size; }//먼저 생성됨. int size=32됨
	int getSize() { return size; } //멤버 함수
};

//class WideTV는 public 범위로 TV를 상속받고 있다.
class WideTV : public TV {
	bool videoIn;
public:
	WideTV(int size, bool videoIn) :TV(size) {//인자있는 생성자 호출
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};

//class SmartTV는 public 범위로 WideTVTV를 상속받고 있다.
class SmartTV :public  WideTV {
	string ipAddr; //인터넷 주소
public:
	//상위 클래스 중에서 인자가 있는 생성자를 호출함 -> 초기화 리스트가 명시적으로 선택되어있음.
	//들어온 size가 그대로 WideTV의 (size,true)의 size에 그대로 넘어감
	SmartTV(string ipAddr, int size) : WideTV(size,true) {
		this->ipAddr = ipAddr;
	}
	string getIpAddr() { return ipAddr; }
};

int main() {

	SmartTV htv("192.0.0.1", 32); //SmartTV객체만 생성
	cout << "size = " << htv.getSize() << endl;
	cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;
	cout << "IP= " << htv.getIpAddr() << endl;
}
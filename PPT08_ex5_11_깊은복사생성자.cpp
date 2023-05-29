#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//예제 5-11: 깊은 복사 생성자를 가진 정상적인 Person 클래스

class Person {//Person클래스 선언
	char* name;
	int id;
public:
	Person(int id, const char* name);//생성자
	Person(const Person& person);// 복사 생성자
	~Person(); //소멸자
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

//생성자 구현부
Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name); //name의 문자 개수
	this->name = new char[len + 1];//name 문자열 공간 할당
	strcpy(this->name, name); //name에 문자열 복사
}

// ------ 깊은 복사 생성자 작성 ------
Person::Person(const Person& p) {
	this->id = p.id;
	int len = strlen(p.name); ///name의 문자 개수
	this->name = new char[len+1]; //name을 위한 공간 할당
	strcpy(this->name, p.name); //name의 문자열 복사
	cout << "복사 생성자 실행, 원본 객체의 이름 " << this->name << endl;
}

//소멸자
Person::~Person() {
	if (name) {//만약 name에 동적 할당된 배열이 있으면?
		delete[] name;
		name = NULL; //delete 후에 NULL을 넣는 것이 더 바람직하다
	}
}

//이름변경
void Person::changeName(const char* name) {

	//현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다
	if (strlen(name) > strlen(this->name)) //만약 name문자열 길이가 필드의 name보다 크다면?
		return; //종료
	strcpy(this->name, name); //문자열 길이가 적절하면 문자열 복사하기 -> 변경하기
}

int main() {

	Person father(1, "kitae"); //father객체 생성
	Person daughter(father); //daughter 객체 복사 생성. 복사 생성자 호출

	cout << "daughter 객체 생성 직후 --- " << endl;
	father.show(); //father 객체 출력
	daughter.show();//daughter 객체 출력

	daughter.changeName("Grace"); //이름 변경
	cout << "daughter 이름을 Grace로 변경한 후 --- " << endl;
	father.show();//father 객체 출력
	daughter.show();//daughter 객체 출력

	return 0; //소멸자 실행
}
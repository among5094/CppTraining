#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//예제 5-10: 얕은 복사 때문에 프로그램이 비정상적으로 종료되는 경우

class Person {//Person클래스 선언
	char* name;
	int id;
public:
	Person(int id, const char* name);//생성자
	~Person(); //소멸자
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

/*
만약 복사생성자가 삽입된다면 어떤 형태일까?

Person::Person(const Person& p) {
	this->id = p.id;
	this->name = p.name;
}
 --> 참조 매개 변수 p로 원본 객체의 id와 name포인터를 사본객체(this)에 복사한다. 

*/

Person::Person(int id, const char* name) { //생성자
	this->id = id;
	int len = strlen(name); //name의 문자 개수
	this->name = new char[len + 1];//name 문자열 공간 할당
	strcpy(this->name, name); //name에 문자열 복사
}

Person::~Person() {
	if (name){//만약 name에 동적 할당된 배열이 있으면?
		delete[] name;
		name = NULL; //delete 후에 NULL을 넣는 것이 더 바람직하다
	}
}

void Person::changeName(const char* name) {
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

int main() {
	Person father(1, "kitae"); //father객체 생성
	Person daughter(father); //디폴트 복사 생성자 호출 -> 여기에서 메모리 공유가 일어남
	//그러나 얕은 복사라서 주소값만 복사하고 메모리를 공유한다.

	cout << "daughter 객체 생성 직후 --- " << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace"); 
	cout << "daughter 이름을 Grace로 변경한 후 --- " << endl;
	father.show();//문제1: 디폴트 생성자 때문에 메모리 공유가 일어나므로 아빠의 이름도 같이 변경된다
	daughter.show();	
	
	return 0;
	/* return 0; 문제
	문제2: daughter 객체에 소멸자가 실행된 후 name에 할당된 메모리는 힙메모리에 반환됨.
	그리고 father 객체의 소멸자가 실행될 때, 이미 반환된 name의 메모리를 다시 반환하게 되므로 오류! -> 비정상 종료
	*/
}
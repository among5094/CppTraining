#include <iostream>
using namespace std;

//예제 5_8: 참조리턴 해보기

//배열s의 index원소 공간에 대한 "참조"를 return하는 함수
char& find(char s[], int index) { 
	return s[index]; //참조 리턴
}

int main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S'; //name 배열의 0번째를 'S'로 변경
	cout << name << endl;

	//ref는 name의 index가 2인 곳에 대한 "참조(별명)"
	char& ref = find(name, 2);
	ref = 't'; //name="Site"
	cout << name << endl;
	
}
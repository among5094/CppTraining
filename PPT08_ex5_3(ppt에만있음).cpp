#include <iostream>
using namespace std;

//예제5-3(PPT에만 있음, ppt19쪽)
//목적: 서로 가리키는 size가 같은지 보기

int main() {
	
	int num = 10;
	int& ref = num;
	
	cout << "num의 크기: "<<sizeof(num) << endl;
	cout << "ref의 크기: " << sizeof(ref) << endl; //ref의 크기가 num의 크기임 -> ref가 num의 별명이니까

	cout << "char 형의 크기>> " << sizeof(char) << endl;
	cout << "char& 형의 크기>> " << sizeof(char&) << endl;

	return 0;
}
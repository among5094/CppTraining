#include <iostream>
using namespace std;

//예제5-3(교재p.234)
//목적: 기본 타입 변수에 대한 참조(reference)

int main() {

	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1;
	int n = 2;
	int& refn = n; //refn이 변수n을 가리킴 + 별명(reference)은 반드시 초기화 시켜주기!!
	n = 4;
	refn++; //refn=5, n=5
	cout << i << '\t' << n << '\t' << refn << endl;

	refn = i; //refn=1, n=1
	refn++; //refn=2, n=2
	cout << i << '\t' << n << '\t' << refn << endl;

	int* p = &refn; //포인터 변수p는 n의 주소를 가짐. n의 별명이 refn이다. 
	*p = 20; //refn=20, n=20
	cout << i << '\t' << n << '\t' << refn << endl;

}
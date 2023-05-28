#include <iostream>
using namespace std;

//예제5-5: 참조 매개 변수로 평균 리턴하기
//목적: 참조 매개 변수가 필요한 사례 

bool average(int a[], int size, int& avg) { //평균값을 전달하기 위해 참조 매개 변수(avg)추가함
	
	if (size <= 0) //배열의 사이즈가 음수이면
		return false; //즉시 종료 

	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	avg = sum / size; //평균 구하기
	return true;
}

int main() {

	int x[] = { 0,1,2,3,4,5 };
	int avg;

	//avg에는 평균이 넘어오고, average()는 true를 리턴한다.
	if (average(x, 6, avg)) 
		cout << "평균은 " << avg << endl;
	else
		cout<< "매개변수오류" << endl;


	//avg의 값은 의미 없고, average()는 false를 리턴
	if (average(x, -2, avg)) //배열의 size가 음수니까 오류
		cout << "평균은 " << avg << endl;
	else
		cout << "매개변수오류" << endl;
}

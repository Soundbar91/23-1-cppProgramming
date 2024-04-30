#pragma once // 해당 헤더 파일이 한번만 빌드되도록 한다.
#include <iostream>
#include <string>
// 캔버스의 최대 높이를 상수로 선언
#define MAXLINES 100
// cin, cout 사용하기 위해 이름 공간 선언
using namespace std;

// 가상의 화면 Canvas 클래스 선언
class Canvas {

	// 가로와 세로의 크기를 저장하는 변수를 private 멤버 변수로 선언
	int xMax, yMax;
	// Canvas 각 줄을 저장하기 위해 문자열 배열 string으로 선언
	string Line[MAXLINES];

public:

	// Canvas 클래스의 생성자 선언
	// 캔버스의 크기를 받아 설정한다.
	// 반복문을 이용하여 Canvas 문자열 배열에서 xMax * 2의 위치마다 빈칸을 저장
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {
		for (int y = 0; y < yMax; y++) Line[y] = string(xMax * 2, ' ');
	}

	// Canvas에서 해당 되는 위치의 값을 val로 변경하는 함수
	void Draw(int x, int y, string val) {
		// 해당 좌표가 Canvas 내부에 있는지 검사
		// string의 replace 함수를 이용하여 x * 2의 위치의 값을 val로 변경
		if (x >= 0 && y >= 0 && x < xMax && y < yMax) Line[y].replace(x * 2, 2, val);
	}

	// Canvas의 모든 값을 val로 변경하는 함수
	void Clear(string val = ". ") {

		// 반복문과 Draw 함수를 이용하여 val 값으로 변경한다.
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				Draw(x, y, val);
			}
		}

	}

	// Canvas를 출력하는 함수
	void Print(const char* title = "<My Canvas>") {

		// 화면을 지우고 매개변수로 받은 제목을 출력
		system("cls");
		cout << title << endl;

		// 반복문을 이용하여 문자열 배열 Line를 한 줄씩 출력
		for (int y = 0; y < yMax; y++) cout << Line[y] << endl;
		cout << endl;
	}

};
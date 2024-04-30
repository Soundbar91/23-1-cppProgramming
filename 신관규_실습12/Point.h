#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point {

private:
	// 점의 x와 y 좌표 값을 저장할 변수
	int x, y;
	// Monster를 친구 클래스로 등록
	friend class Monster;
	// Canvas를 친구 클래스로 등록
	friend class Canvas;

public:
	// Point 클래스의 생성자
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}

	// 인덱스 연산자를 중복하여 private 멤버 변수로 있는 x와 y에 접근이 가능하도록 한다.
	int& operator[] (int id) {

		// 인덱스 0과 1를 각각 x와 y로 사용한다.
		if (id == 0) return x;
		else if (id == 1) return y;
		// 그 이외의 입력이 들어오면 프로그램을 종료한다.
		else exit(0);

	}

	// double로의 형 변환 연산자로, 원점에서부터의 유클리드 거리를 반환한다.
	operator double() { return sqrt((double) x * x + y * y); }

	// 함수 호출 연산자 중복 함수로, 좌표를 영역안에 있도록 조정을 한다.
	void operator() (int maxx, int maxy) {

		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;

	}

	// 연산자 -를 중복하여 좌표의 부호를 바꿔서 Point 클래스를 반환한다.
	Point operator- () { return Point(-x, -y); }
	// 연산자 ==를 중복하여 좌표의 일치 여부에 따라 참과 거짓을 반환한다.
	bool operator== (Point p) { return x == p.x && y == p.y; }
	// 연산자 !=를 중복하여 좌표의 불일치 여부에 따라 참과 거짓을 반환한다.
	bool operator!= (Point p) { return x != p.x || y != p.y; }
	// 연산자 -를 중복하여 좌표를 감산 후 Point 클래스를 반환한다.
	Point operator- (Point p) { return Point(x - p.x, y - p.y); }
	// 연산자 +를 중복하여 좌표를 가산 후 Point 클래스를 반환한다.
	Point operator+ (Point p) { return Point(x + p.x, y + p.y); }
	// 연산자 +=를 중복하여 좌표를 가산한다.
	void operator+= (Point p) { x += p.x, y += p.y; }
	// 연산자 -=를 중복하여 좌표를 감산한다.
	void operator-= (Point p) { x -= p.x, y -= p.y; }

};

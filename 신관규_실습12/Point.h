#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point {

private:
	// ���� x�� y ��ǥ ���� ������ ����
	int x, y;
	// Monster�� ģ�� Ŭ������ ���
	friend class Monster;
	// Canvas�� ģ�� Ŭ������ ���
	friend class Canvas;

public:
	// Point Ŭ������ ������
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}

	// �ε��� �����ڸ� �ߺ��Ͽ� private ��� ������ �ִ� x�� y�� ������ �����ϵ��� �Ѵ�.
	int& operator[] (int id) {

		// �ε��� 0�� 1�� ���� x�� y�� ����Ѵ�.
		if (id == 0) return x;
		else if (id == 1) return y;
		// �� �̿��� �Է��� ������ ���α׷��� �����Ѵ�.
		else exit(0);

	}

	// double���� �� ��ȯ �����ڷ�, �������������� ��Ŭ���� �Ÿ��� ��ȯ�Ѵ�.
	operator double() { return sqrt((double) x * x + y * y); }

	// �Լ� ȣ�� ������ �ߺ� �Լ���, ��ǥ�� �����ȿ� �ֵ��� ������ �Ѵ�.
	void operator() (int maxx, int maxy) {

		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;

	}

	// ������ -�� �ߺ��Ͽ� ��ǥ�� ��ȣ�� �ٲ㼭 Point Ŭ������ ��ȯ�Ѵ�.
	Point operator- () { return Point(-x, -y); }
	// ������ ==�� �ߺ��Ͽ� ��ǥ�� ��ġ ���ο� ���� ���� ������ ��ȯ�Ѵ�.
	bool operator== (Point p) { return x == p.x && y == p.y; }
	// ������ !=�� �ߺ��Ͽ� ��ǥ�� ����ġ ���ο� ���� ���� ������ ��ȯ�Ѵ�.
	bool operator!= (Point p) { return x != p.x || y != p.y; }
	// ������ -�� �ߺ��Ͽ� ��ǥ�� ���� �� Point Ŭ������ ��ȯ�Ѵ�.
	Point operator- (Point p) { return Point(x - p.x, y - p.y); }
	// ������ +�� �ߺ��Ͽ� ��ǥ�� ���� �� Point Ŭ������ ��ȯ�Ѵ�.
	Point operator+ (Point p) { return Point(x + p.x, y + p.y); }
	// ������ +=�� �ߺ��Ͽ� ��ǥ�� �����Ѵ�.
	void operator+= (Point p) { x += p.x, y += p.y; }
	// ������ -=�� �ߺ��Ͽ� ��ǥ�� �����Ѵ�.
	void operator-= (Point p) { x -= p.x, y -= p.y; }

};

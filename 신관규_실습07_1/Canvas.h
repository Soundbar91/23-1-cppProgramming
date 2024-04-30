#pragma once // �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
#include <iostream>
#include <string>
// ĵ������ �ִ� ���̸� ����� ����
#define MAXLINES 100
// cin, cout ����ϱ� ���� �̸� ���� ����
using namespace std;

// ������ ȭ�� Canvas Ŭ���� ����
class Canvas {

	// ���ο� ������ ũ�⸦ �����ϴ� ������ private ��� ������ ����
	int xMax, yMax;
	// Canvas �� ���� �����ϱ� ���� ���ڿ� �迭 string���� ����
	string Line[MAXLINES];

public:

	// Canvas Ŭ������ ������ ����
	// ĵ������ ũ�⸦ �޾� �����Ѵ�.
	// �ݺ����� �̿��Ͽ� Canvas ���ڿ� �迭���� xMax * 2�� ��ġ���� ��ĭ�� ����
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {
		for (int y = 0; y < yMax; y++) Line[y] = string(xMax * 2, ' ');
	}

	// Canvas���� �ش� �Ǵ� ��ġ�� ���� val�� �����ϴ� �Լ�
	void Draw(int x, int y, string val) {
		// �ش� ��ǥ�� Canvas ���ο� �ִ��� �˻�
		// string�� replace �Լ��� �̿��Ͽ� x * 2�� ��ġ�� ���� val�� ����
		if (x >= 0 && y >= 0 && x < xMax && y < yMax) Line[y].replace(x * 2, 2, val);
	}

	// Canvas�� ��� ���� val�� �����ϴ� �Լ�
	void Clear(string val = ". ") {

		// �ݺ����� Draw �Լ��� �̿��Ͽ� val ������ �����Ѵ�.
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				Draw(x, y, val);
			}
		}

	}

	// Canvas�� ����ϴ� �Լ�
	void Print(const char* title = "<My Canvas>") {

		// ȭ���� ����� �Ű������� ���� ������ ���
		system("cls");
		cout << title << endl;

		// �ݺ����� �̿��Ͽ� ���ڿ� �迭 Line�� �� �پ� ���
		for (int y = 0; y < yMax; y++) cout << Line[y] << endl;
		cout << endl;
	}

};
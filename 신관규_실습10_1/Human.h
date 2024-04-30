#pragma once // �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
#include "Monster.h"
#include <conio.h>
// ����Ű�� ���� ���������� �����Ѵ�.
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

// ������ ����� ���� �޸� Ŭ����
class Human : public Monster {

public:
	// �޸� Ŭ������ �������̸�, ������ �̸�, ��� ȭ��, ���� ��ġ�� �Ű� ������ �޾� ���� Ŭ������ �ʱ�ȭ�Ѵ�.
	Human(string n = "�̷��η�1,", string i = "��", int px = 0, int py = 0) : Monster(n, i, px, py) {}
	// �޸� Ŭ������ �Ҹ����̸� ���ڸ� ����Ѵ�.
	~Human() { cout << "[Huamn]"; }

	// ȭ��ǥ�� �Է´� �Լ��̸� �Է¹��� Ű�� ȭ��ǥ�̸� ȭ��ǥ Ű�� ��ȯ�Ѵ�.
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }

	// �ΰ� Ŭ�������� ������ �� Move �Լ�
	void Move(int** map, int maxx, int maxy) {

		// ȭ��ǥ�� �Է��� �Ǿ����� �̵��� �ǵ��� �Ѵ�.
		if (_kbhit()) {

			// �Էµ� ȭ��ǥ�� ������ ������ ����
			char ch = getDirKey();

			// �Էµ� ȭ��ǥ�� ���� �����¿츦 �����̵��� �Ѵ�.
			if (ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;

			// ������ ��ǥ�� �� �ܺη� �������� Ȯ���Ͽ� ��ġ ������ �Ѵ�.
			// �������� �ִ��� Ȯ���Ͽ� �������� �Դ´�.
			Clip(maxx, maxy);
			Eat(map);

		}
	}
};

// �޸� Ŭ������ ����� ���� Tuman Ŭ����
class Tuman : public Human {

public:
	// Tuman Ŭ������ �������̸�, ������ �̸�, ��� ȭ��, ���� ��ġ�� �Ű� ������ �޾� �޸� Ŭ������ �ʱ�ȭ�Ѵ�.
	Tuman(string n = "�̷��η�2,", string i = "��", int px = 0, int py = 0) : Human(n, i, px, py) {}
	// Tuman Ŭ������ �Ҹ����̸� ���ڸ� ����Ѵ�.
	~Tuman() { cout << "[Tuamn]"; }

	// Tuman Ŭ������ �������� ���� ���Ӱ� ���� �� �Լ�
	void Move(int** map, int maxx, int maxy, unsigned char CH) {

		// ȭ��ǥ�� ������ �� �ش� �������� �����̵��� �Ѵ�.
		if (CH== Left) x--;
		else if (CH == Right) x++;
		else if (CH == Up) y--;
		else if (CH == Down) y++;

		// a, d, w, s�� ������ �� �ش� �������� �����̵��� �Ѵ�.
		else if (CH == 'a') x--;
		else if (CH == 'd') x++;
		else if (CH == 'w') y--;
		else if (CH == 's') y++;
		else return;

		// ������ ��ǥ�� �� �ܺη� �������� Ȯ���Ͽ� ��ġ ������ �Ѵ�.
		// �������� �ִ��� Ȯ���Ͽ� �������� �Դ´�.
		Clip(maxx, maxy);
		Eat(map);

	}

};

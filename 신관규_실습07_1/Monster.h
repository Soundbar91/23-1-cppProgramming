#pragma once // �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
#include "Canvas.h"
// ���� ũ�⸦ ����� ����
#define DIM 40

// ���ӿ��� ��� �� Monster Class ����
class Monster {

private:

	// ������ �̸�, ��� ���, ���� ��ġ, ���� �������� ���� �׸��� �������� �����ϱ� ���� private ��� ������ ����
	string Name, icon;
	int x, y, nItem, nEnergy;

	// ������ ��ġ�� �������ִ� �Լ�
	void Clip(int maxx, int maxy) {

		// ���ǹ��� �̿��Ͽ� ������ ��ǥ�� �˻�
		// ���Ͱ� �� ������ ������ �Ǹ� ��ġ�� �������ش�
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;

	}

	// ���Ͱ� �������� �Դ� �Լ�
	void Eat(int Map[DIM][DIM]) {

		// ���ǹ��� �̿��ؼ� ������ ���� Ȯ��
		// �������� �ִٸ� �ش� ��ġ�� ���� �����Ͽ� �������� ������ �Ѵ�.
		// ���� �������� ������ �������� ���� ��Ų��.
		if (Map[y][x] == 1) {
			Map[y][x] = 0;
			nItem++;
			nEnergy += 8;
		}
		// ���� ������ ��ǥ�� �������� ���� �������� �ּڰ����� ū �����̸�, �������� ���ҽ�Ų��.
		else if (Map[y][x] != 1 && nEnergy > 0) nEnergy -= 1;

	}

public:

	// Monster class�� ������
	// ������ �̸�, ��� ȭ��, ���� ��ġ�� �Ű� ������ �޾� �����Ѵ�.
	// �����۰� �������� 0�� 100���� �ʱ�ȭ�Ѵ�.
	Monster(string n = "������", string i = "��", int px = 0, int py = 0) : Name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) { }
	// Monster class�� �Ҹ���
	// ������ ����ǰ� ���Ͱ� ������� �޼����� ����Ѵ�.
	~Monster() { cout << "\t" << Name << icon << " �������ϴ�~~~\n"; }

	// ���͸� Canvas�� ����ϴ� �Լ�
	// canvas Ŭ������ Draw �Լ��� ������ ��ġ�� ��� ȭ���� �Ѱ� ȭ�鿡 ����Ѵ�.
	void Draw(Canvas& canvas) { canvas.Draw(x, y, icon); }

	// ���͸� �������� �����̴� �Լ�
	void Move(int Map[DIM][DIM], int maxx, int maxy) {

		// switch-case�� �̿��Ͽ� ������ ��쿡 ���� ���͸� �ű��.
		switch (rand() % 8) {

			case 0: y--; break;
			case 1: x++; y--; break;
			case 2: x++; break;
			case 3: x++; y++; break;
			case 4: y++; break;
			case 5: x--; y++; break;
			case 6: x--; break;
			case 7: x--; y--; break;

		}

		// ������ ��ǥ�� �� �ܺη� �������� Ȯ���Ͽ� ��ġ ������ �Ѵ�.
		// �������� �ִ��� Ȯ���Ͽ� �������� �Դ´�.
		Clip(maxx, maxy);
		Eat(Map);

	}

	// ������ ������ ����ϴ� �Լ�
	// ������ �̸�, ��� ȭ��, ���� �������� ���� �׸��� ������ ���¸� ���
	void Print() { cout << "\t" << Name << icon << ":" << nItem << " E:" << nEnergy <<  endl; }

};
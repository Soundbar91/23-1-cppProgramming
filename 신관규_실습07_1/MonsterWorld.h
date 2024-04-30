#pragma once // �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
#include "Canvas.h"
#include "Monster.h"
#include <windows.h>
// ���� ũ�⸦ ����� ����
#define DIM 40
// ���͸� ������ �迭 ũ�⸦ ����� ����
#define MAXMONS 20

// MonsterWorld Class ����
class MonsterWorld {

private:

	// ���Ϳ����� �� ����
	// �ش� ���� �Ϻκθ� ����ϱ� ���� xMax, yMax ���� ����
	// ������ ��ü �̵� ȸ���� ���� ������ ���� �����ϱ� ���� ���� ����
	int map[DIM][DIM];
	int xMax, yMax, nMon, nMove;
	// ���͵��� �����ϱ� ���� ��ü �迭 ����
	// MonsterWorld�� ����� Canvas ��ü ����
	Monster mon[MAXMONS];
	Canvas canvas;

	// MonsterWorld�� �����ϱ� ���� ������ �Լ� ����
	int& Map(int x, int y) { return map[y][x]; }
	// ������ ���� ������ �˻��ϱ� ���� bool �Լ� ����
	bool isDone() { return countItems() == 0; }

	// MonsterWorld�� �����ִ� �������� ������ ���� �Լ�
	int countItems() {

		// �������� ������ �����ϱ� ���� ����
		int nItems = 0;

		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				if (Map(x, y) > 0) nItems++;
			}
		}

		return nItems;

	}

	// MonsterWorld�� ȭ�鿡 ����ϴ� �Լ�
	void Print() {

		// canvas Ŭ������ Clear �Լ��� �̿��Ͽ� ĵ���� �ʱ�ȭ�Ѵ�.
		canvas.Clear();

		// �ݺ����� �̿��Ͽ� canvas Ŭ������ Draw �Լ��� �̿��Ͽ� ĵ������ �ʱ�ȭ �� ���� �� ���ڷ� �ٲ۴�.
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				if (Map(x, y) > 0) canvas.Draw(x, y, "��");
			}
		}

		// �ݺ����� �̿��Ͽ� Monster Ŭ������ Draw �Լ��� �̿��Ͽ� ���͸� ĵ������ ����Ѵ�.
		for (int i = 0; i < nMon; i++) mon[i].Draw(canvas);
		canvas.Print("[ Monster World (Basic) ]");

		// ��ü �̵� ���� ���� ������ ���� ����Ѵ�.
		cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;
		cerr << " ���� ������ �� = " << countItems() << endl;

		// Monster Ŭ������ Print �Լ��� �̿��Ͽ� ������ ������ ����Ѵ�.
		for (int i = 0; i < nMon; i++) mon[i].Print();

	}

public:

	// MonsterWorld class�� ������
	// ĵ������ ũ��� �� ������ ȸ��, ���� ���� ���� �ʱ�ȭ�Ѵ�.
	MonsterWorld(int w, int h) : canvas(w, h), xMax(w), yMax(h) {

		nMon = 0;
		nMove = 0;
		// �ݺ����� �̿��Ͽ� ���� ������ ��� ��ġ�� �������� �ֵ��� 1�� �����Ѵ�.
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				Map(x, y) = 1;
			}
		}
	}
	// MonsterWorld Class�� �Ҹ���
	// �ƹ��� ���� ���� �ʴ´�.
	~MonsterWorld() { }

	// MonsterWorld�� ���͸� �߰��ϴ� �Լ�
	// �� ������ ���� ����� ������ ������ ������ ���͸� �����ϴ� mon �迭�� ���͸� �߰��Ѵ�.
	void Add(Monster m) { if (nMon < MAXMONS) mon[nMon++] = m; }
	
	// ������ ����Ǵ� �Լ�
	// �����̴� ȸ���� �ִ� ����, �����ð��� �Ű������� �޴´�.
	void Play(int maxwalk, int wait) {
		
		// MonsterWorld�� ����Ѵ�. 
		Print();
		cerr << " ���͸� ��������...";
		getchar();

		// �ݺ����� �̿��Ͽ� ���͸� �̵��ϰ� ȭ���� �����ϴ� ������ �����Ѵ�.
		for (int i = 0; i < maxwalk; i++) {
			// �ݺ����� Monster Ŭ������ Move �Լ��� �̿��Ͽ� ���͸� �����δ�.
			for (int k = 0; k < nMon; k++) {
				mon[k].Move(map, xMax, yMax);
			}

			// �� �����̴� ȸ���� ������Ű��, ȭ���� �����Ͽ� ����Ѵ�.
			nMove++;
			Print();
			// ���� ���� ������ �˻��Ѵ�.
			if (isDone()) break;
			// Sleep �Լ��� �̿��Ͽ� ȭ���� ���� �����̴� ���� �����Ѵ�.
			Sleep(wait);
		}

	}

};
#pragma once // �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
#include "Canvas.h"
#include "Monster.h"
#include "Matrix.h"
#include "Human.h"
#include "VariousMonsters.h"
#include <windows.h>
// ���� ũ�⸦ ����� ����
#define DIM 40
// ���͸� ������ �迭 ũ�⸦ ����� ����
#define MAXMONS 20

// MonsterWorld Class ����
class MonsterWorld {

private:

	// Matrix ��ü world�� ����
	Matrix world;
	// �ش� ���� �Ϻκи� ����ϱ� ���� xMax, yMax ���� ����
	int xMax, yMax;
	// ������ ��ü �̵� ȸ���� ���� ������ ���� �����ϱ� ���� ���� ����
	int nMon, nMove;
	// ���� ��ü�� ������ ���� ������ �迭�� ����
	Monster* pMon[MAXMONS];
	// MonsterWorld�� ����� Canvas ��ü ����
	Canvas canvas;

	// MonsterWorld�� �����ϱ� ���� ������ �Լ� ����
	int& Map(int x, int y) { return world.elem(x, y); }
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
		for (int i = 0; i < nMon; i++) pMon[i]->Draw(canvas);
		canvas.Print("[ Monster World (���η� ź��) ]");

		// ��ü �̵� ���� ���� ������ ���� ����Ѵ�.
		cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;
		cerr << " ���� ������ �� = " << countItems() << endl;

		// Monster Ŭ������ Print �Լ��� �̿��Ͽ� ������ ������ ����Ѵ�.
		for (int i = 0; i < nMon; i++) pMon[i]->Print();

		// ��ü ������ ���� ����Ѵ�.
		Monster::printCount();
	}

public:

	// MonsterWorld class�� ������
	// ĵ������ ũ��� �� ������ ȸ��, ���� ���� ���� �ʱ�ȭ�Ѵ�.
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {

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
	// �������� �����Ǿ��� ���͵��� �����Ѵ�.
	~MonsterWorld() { 
		for (int i = 0; i < nMon; i++) {
			delete pMon[i];
		}
	}

	// MonsterWorld�� ���͸� �߰��ϴ� �Լ�
	// �� ������ ���� ����� ������ ������ ������ ���͸� �����ϴ� mon �迭�� ���͸� �߰��Ѵ�.
	void Add(Monster* m) { if (nMon < MAXMONS) pMon[nMon++] = m; }

	void checkStarvation() {

		// �ݺ����� �̿��Ͽ� ���͵��� �������� �˻��Ѵ�.
		for (int i = 0; i < nMon; i++) {

			if (pMon[i]->getEnergy() <= 0) {

				delete pMon[i];
				pMon[i] = pMon[nMon - 1];

				nMon--;
				i--;
			}

		}
	}

	// ������ ����Ǵ� �Լ�
	// �����̴� ȸ���� �ִ� ����, �����ð��� �Ű������� �޴´�.
	void Play(int maxwalk, int wait) {
		
		// MonsterWorld�� ����Ѵ�. 
		Print();
		cerr << " ���͸� ��������...";
		getchar();

		// �ݺ����� �̿��Ͽ� ���͸� �̵��ϰ� ȭ���� �����ϴ� ������ �����Ѵ�.
		for (int i = 0; i < maxwalk; i++) {

			for (int i = 2; i < nMon; i++) pMon[i]->Move(world.Data(), xMax, yMax);

			// Ű������ �Է��� ����� Tuman Ŭ������ �߰��� �ΰ����� �̵��Ѵ�.
			if (_kbhit()) {

				// �Է¹��� ���ڸ� ������ ���� ����
				unsigned char ch = _getche();

				// ȭ��ǥ�� �Է��� ���� �� �ش� �������� �����δ�.
				if (ch == 224) {

					ch = _getche();
					((Tuman*)pMon[1])->Move(world.Data(), xMax, yMax, ch);
	
				}
				// a,w,s,d�� ������ �� �ش� �������� �����δ�.
				else ((Tuman*)pMon[0])->Move(world.Data(), xMax, yMax, ch);

			}

			// �� �����̴� ȸ���� ������Ű��, ȭ���� �����Ͽ� ����Ѵ�.
			nMove++;
			Print();
			checkStarvation();
			// ������ ���� 0�� �Ǹ� ������ �����Ѵ�.
			if (nMon == 0) break;
			// ���� ���� ������ �˻��Ѵ�.
			if (isDone()) break;
			// Sleep �Լ��� �̿��Ͽ� ȭ���� ���� �����̴� ���� �����Ѵ�.
			Sleep(wait);
		}

	}

};
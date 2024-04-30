#pragma once // �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
#include "Canvas.h"
#include "Point.h"
// ���� ũ�⸦ ����� ����
#define DIM 40

// ���ӿ��� ��� �� Monster Class ����
class Monster {

// ����� �ϱ� ���� ���� private�� ��� ���� �� �Լ��� protected�� ��� ���� �� �Լ��� ����
protected:

	// ������ �̸�, ��� ���, ���� �������� ���� �׸��� �������� �����ϱ� ���� ���� ����
	string Name, icon;
	int nItem, nEnergy;
	// ������ġ(p)�� ���� ��ġ(q)�� �����ϴ� Point Ŭ���� ��ü ����
	Point q, p;
	// ���Ͱ� ����� �ϴ� Ƚ���� ������ ���� ����
	int nSleep;
	// ���Ͱ� ���� �� ���� ������ �Ÿ��� ������ ���� ����
	double dist;
	// ���Ͱ� ������ �� �Ÿ��� ������ ���� ����
	double total;

	// ������ ��ġ�� �������ִ� �Լ�
	// Point.h�� ���ǵ� �Լ� ȣ�� �����ڸ� �̿��Ѵ�.
	void Clip(int maxx, int maxy) { p(maxx, maxy); }

	// ���Ͱ� �������� �Դ� �Լ�
	void Eat(int** Map) {

		// ���ǹ��� �̿��ؼ� ������ ���� Ȯ��
		// �������� �ִٸ� �ش� ��ġ�� ���� �����Ͽ� �������� ������ �Ѵ�.
		// ���� �������� ������ �������� ���� ��Ų��.
		if (Map[p.y][p.x] == 1) {
			Map[p.y][p.x] = 0;
			nItem++;
			nEnergy += 8;
		}
		// ���� ������ ��ǥ�� �������� ���� �������� �ּڰ����� ū �����̸�, �������� ���ҽ�Ų��.
		else if (Map[p.y][p.x] != 1 && nEnergy > 0) {
			// �������� ������ ��µǴ� ��Ȳ�� �����Ѵ�.
			if (nEnergy - 5 < 0) nEnergy = 0;
			else nEnergy -= 5;
		}
		
		// Point Ŭ������ ���� ������ -�� �� ��ȯ �����ڸ� ����Ͽ� dist�� total ������ ������ �Ÿ� ��ŭ ���� ������Ų��.
		dist += (double)(p - q);
		total += (double)(p - q);
		// ���� ��ġ�� ���� ��ġ�� �����Ѵ�.
		q = p;

		// dist�� ���� 0 �̻��̸� ���Ͱ� ������ �Ѵ�.
		if (dist > 20) {
			dist = 0;
			nSleep = 10;
		}

	}

	// ���Ͱ� ���� �ִ� ���������� �˻��ϴ� �Լ�
	bool isSleep() {

		// ���� �ִ� �����̸� nSleep�� �ϳ� �ٿ��ְ� true�� ��ȯ�Ѵ�.
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		// ���� ���� �ʴ� ���°� �ƴϸ� false�� ��ȯ�Ѵ�.
		else return false;

	}

public:
	// ������ ���� ��Ÿ���� ���� ��� ���� �߰�
	static int nMonster;

	// Monster class�� ������
	// ������ �̸�, ��� ȭ��, ���� ��ġ�� �Ű� ������ �޾� �����Ѵ�.
	// �����۰� �������� 0�� 100���� �ʱ�ȭ�Ѵ�.
	// ���Ͱ� ������ �� ���� ������ ���� �������״�.
	Monster(string n = "������", string i = "��", int x = 0, int y = 0) : Name(n), icon(i), q(x,y), p(x,y), nSleep(0), dist(0.0),total(0.0), nItem(0), nEnergy(100) {
		Monster::nMonster++;
	}
	// Monster class�� ���� �Ҹ���
	virtual ~Monster() {

		// �������� ���� ���� ����ϴ� ������ �ٸ��� �����Ͽ���.
		// ���Ͱ� ���� ������ ������ ���� ���ҽ��״�.
		if (nEnergy <= 0) {
			cout << Name << icon << " �����׾����ϴ�~~~~\n";
			Monster::nMonster--;
		}
		else if (nEnergy > 0){
			cout << Name << icon << " �������ϴ�~~~\n";
			Monster::nMonster--;
		}

	}

	// ���͸� Canvas�� ����ϴ� �Լ�
	// canvas Ŭ������ Draw �Լ��� ������ ��ġ�� ��� ȭ���� �Ѱ� ȭ�鿡 ����Ѵ�.
	void Draw(Canvas& canvas) { canvas.Draw(p[0], p[1], icon); }

	// ���� �������� ��ȯ�ϴ� �Լ�
	int getEnergy() { return nEnergy; }

	// ��ü ���� ���� ����ϴ� ���� ��� �Լ�
	static void printCount() { printf(" ��ü ������ �� : %d\n", Monster::nMonster); }

	// ���͸� �������� �����̴� �Լ�
	// ���� �Լ��� ����
	virtual void Move(int** Map, int maxx, int maxy) {

		// ���� ���� �ʴ� ��쿡�� �̵��� �����Ѵ�. 
		if (!isSleep()) {
			int num = rand() % 9 + 1;
			p += Point(num % 3 - 1, num / 3 - 1);

			// ������ ��ǥ�� �� �ܺη� �������� Ȯ���Ͽ� ��ġ ������ �Ѵ�.
			// �������� �ִ��� Ȯ���Ͽ� �������� �Դ´�.
			Clip(maxx, maxy);
			Eat(Map);

		}
		
	}

	// ������ ������ ����ϴ� �Լ�
	// ������ �̸�, ��� ȭ��, ���� �������� ���� �׸��� ������ ���¸� ���
	void Print() { cout << "\t" << Name << icon << ":" << nItem << " E:" << nEnergy <<  endl; }

};
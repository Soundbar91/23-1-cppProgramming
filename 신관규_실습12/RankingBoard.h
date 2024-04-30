#pragma once
#include <iostream>
#include <fstream>
#include "FileException.h"
using namespace std;
#define NUM_MVP 5

// ���� ������ �����ϴ� Ŭ����
struct PlayInfo {

	// ���̸��� �̸�, ȹ���� ������ ��, �̵� �Ÿ��� ȹ���� �������� ���� ��� ������ �����ߴ�.
	string name;
	int nItem;
	double itemPerMove;
	// PlayInfo�� �������̴�.
	PlayInfo(string na = "���η�", int ni = 0, double ipm = 0.0) : name(na), nItem(ni), itemPerMove(ipm) {}

};

// ��ŷ�� �����ϴ� Ŭ���� ����
class RankingBoard {
	
	// PlayInfo Ŭ������ ��ü �迭�� ����� �ʱ�ȭ�� nMVP ������ private ��� ������ �����ߴ�.
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;

public:

	// ��ŷ�� �о� ����ϴ� �Լ�
	void load(string filename) {
		
		// ifstream�� ��ü�� �����ϰ� �Ű������� ���� �����̸��� �ش�Ǵ� ������ ����.
		ifstream is;
		is.open(filename);

		// ���� ���� ���⿡ ���и� �ϸ� FileException ���ܸ� ����� ������. �̶�, true�� �����Ѵ�.
		if (!is)
			throw(FileException(filename, true));
		// �ݺ����� �̿��Ͽ� ��ŷ�� ����Ѵ�.
		for (int i = 0; i < nMVP; i++)
			is >> MVP[i].nItem >> MVP[i].name >> MVP[i].itemPerMove;

		// ������ �ݴ´�.
		is.close();
	}

	// ��ŷ�� �����ϴ� �Լ�
	void store(string filename) {

		// ofstream�� ��ü�� �����ϰ� �Ű������� ���� �����̸��� �ش�Ǵ� ������ ����.
		ofstream os;
		os.open(filename);

		// ���� ���� ���⿡ ���и� �ϸ� FileException ���ܸ� ����� ������. �̶�, false�� �����Ѵ�.
		if (!os)
			throw(FileException(filename, false));
		// �ݺ����� �̿��Ͽ� ��ŷ�� �����Ѵ�.
		for (int i = 0; i < nMVP; i++)
			os << MVP[i].nItem << " " << MVP[i].name << " " << MVP[i].itemPerMove << "\n";

		// ������ �ݴ´�.
		os.close();

	}

	// ��ŷ�� ����ϴ� �Լ�
	void print(string title = "���� ��ŷ") {

		// ���� ��ŷ ������ ����Ѵ�.
		cout << endl << title << endl;
		// �ݺ����� �̿��Ͽ� ������ ������ ȭ�鿡 ����Ѵ�.
		for (int i = 0; i < nMVP; i++)
			cout << "[" << i + 1 << "��] " << MVP[i].name << "\t" << MVP[i].nItem << " " << MVP[i].itemPerMove << "\n";
		// ����Ű�� ���� �Լ��� �����Ѵ�.
		cout << "���͸� �Է��ϼ���. ";
		getchar();
		cout << endl;

	}

	// ��ŷ�� �߰��ϴ� �Լ�
	int add(int nItem, double ipm) {

		// ���� ���� �÷��̾��� ������ ������ ��ŷ�� �ִ� ������ �÷��̾� ���� �۰ų� ������ �Լ��� �����Ѵ�.
		if (nItem <= MVP[nMVP - 1].nItem) return 0;

		int pos = nMVP - 1;

		// ���� pos�� ���� �ٿ����� ������ ���Ѵ�
		// ���� ���� �÷��̾��� �������� ������ ���ϴ� �÷��̾�� �۴ٸ� �ݺ����� Ż���Ѵ�.
		// �׷��� �ʴٸ�, �迭�� �� ĭ�� �о ������ �ű��.
		for (; pos > 0; pos--) {
			if (nItem <= MVP[pos - 1].nItem) break;
			MVP[pos] = MVP[pos - 1];
		}

		MVP[pos].nItem = nItem;
		MVP[pos].itemPerMove = ipm;
		
		// �÷��̾��� �̸��� �Է¹޾� �����Ѵ�.
		cout << "\n[" << pos + 1 << "��] �̸��� �Է��ϼ���: ";
		cin >> MVP[pos].name;
		return pos + 1;
	}
};
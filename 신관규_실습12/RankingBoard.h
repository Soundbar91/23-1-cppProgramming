#pragma once
#include <iostream>
#include <fstream>
#include "FileException.h"
using namespace std;
#define NUM_MVP 5

// 게임 정보를 저장하는 클래스
struct PlayInfo {

	// 게이머의 이름, 획득한 아이템 수, 이동 거리당 획득한 아이템의 수를 멤버 변수로 선언했다.
	string name;
	int nItem;
	double itemPerMove;
	// PlayInfo의 생성자이다.
	PlayInfo(string na = "신인류", int ni = 0, double ipm = 0.0) : name(na), nItem(ni), itemPerMove(ipm) {}

};

// 랭킹을 관리하는 클래스 선언
class RankingBoard {
	
	// PlayInfo 클래스의 객체 배열과 상수로 초기화된 nMVP 변수를 private 멤버 변수로 선언했다.
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;

public:

	// 랭킹을 읽어 출력하는 함수
	void load(string filename) {
		
		// ifstream의 객체를 생성하고 매개변수로 받은 파일이름에 해당되는 파일을 연다.
		ifstream is;
		is.open(filename);

		// 만약 파일 열기에 실패를 하면 FileException 예외를 만들어 던진다. 이때, true를 전달한다.
		if (!is)
			throw(FileException(filename, true));
		// 반복문을 이용하여 랭킹을 출력한다.
		for (int i = 0; i < nMVP; i++)
			is >> MVP[i].nItem >> MVP[i].name >> MVP[i].itemPerMove;

		// 파일을 닫는다.
		is.close();
	}

	// 랭킹을 저장하는 함수
	void store(string filename) {

		// ofstream의 객체를 생성하고 매개변수로 받은 파일이름에 해당되는 파일을 연다.
		ofstream os;
		os.open(filename);

		// 만약 파일 열기에 실패를 하면 FileException 예외를 만들어 던진다. 이때, false를 전달한다.
		if (!os)
			throw(FileException(filename, false));
		// 반복문을 이용하여 랭킹을 저장한다.
		for (int i = 0; i < nMVP; i++)
			os << MVP[i].nItem << " " << MVP[i].name << " " << MVP[i].itemPerMove << "\n";

		// 파일을 닫는다.
		os.close();

	}

	// 랭킹을 출력하는 함수
	void print(string title = "게임 랭킹") {

		// 게임 랭킹 문구를 출력한다.
		cout << endl << title << endl;
		// 반복문을 이용하여 현재의 순위를 화면에 출력한다.
		for (int i = 0; i < nMVP; i++)
			cout << "[" << i + 1 << "위] " << MVP[i].name << "\t" << MVP[i].nItem << " " << MVP[i].itemPerMove << "\n";
		// 엔터키를 통해 함수를 종료한다.
		cout << "엔터를 입력하세요. ";
		getchar();
		cout << endl;

	}

	// 랭킹을 추가하는 함수
	int add(int nItem, double ipm) {

		// 만약 현재 플레이어의 아이템 개수가 랭킹에 있는 마지막 플레이어 보다 작거나 같으면 함수를 종료한다.
		if (nItem <= MVP[nMVP - 1].nItem) return 0;

		int pos = nMVP - 1;

		// 변수 pos의 값을 줄여가며 정보를 비교한다
		// 만약 현재 플레이어의 아이템의 개수가 비교하는 플레이어보다 작다면 반복문을 탈출한다.
		// 그렇지 않다면, 배열을 한 칸씩 밀어서 정보를 옮긴다.
		for (; pos > 0; pos--) {
			if (nItem <= MVP[pos - 1].nItem) break;
			MVP[pos] = MVP[pos - 1];
		}

		MVP[pos].nItem = nItem;
		MVP[pos].itemPerMove = ipm;
		
		// 플레이어의 이름을 입력받아 저장한다.
		cout << "\n[" << pos + 1 << "위] 이름을 입력하세요: ";
		cin >> MVP[pos].name;
		return pos + 1;
	}
};
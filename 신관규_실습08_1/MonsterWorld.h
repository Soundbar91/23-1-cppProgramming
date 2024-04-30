#pragma once // 해당 헤더 파일이 한번만 빌드되도록 한다.
#include "Canvas.h"
#include "Monster.h"
#include "Matrix.h"
#include <windows.h>
// 맵의 크기를 상수로 선언
#define DIM 40
// 몬스터를 저장할 배열 크기를 상수로 선언
#define MAXMONS 20

// MonsterWorld Class 선언
class MonsterWorld {

private:

	// Matrix 객체 world를 선언
	Matrix world;
	// 해당 맵의 일부분만 사용하기 위해 xMax, yMax 변수 선언
	int xMax, yMax;
	// 몬스터의 전체 이동 회수와 현재 몬스터의 수를 저장하기 위한 변수 선언
	int nMon, nMove;
	// 몬스터 객체를 저장할 몬스터 포인터 배열을 선언
	Monster* pMon[MAXMONS];
	// MonsterWorld을 출력할 Canvas 객체 선언
	Canvas canvas;

	// MonsterWorld에 접근하기 위해 참조자 함수 선언
	int& Map(int x, int y) { return world.elem(x, y); }
	// 게임의 종료 조건을 검사하기 위해 bool 함수 선언
	bool isDone() { return countItems() == 0; }

	// MonsterWorld에 남아있는 아이템의 개수를 세는 함수
	int countItems() {

		// 아이템의 개수를 저장하기 위한 변수
		int nItems = 0;

		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				if (Map(x, y) > 0) nItems++;
			}
		}

		return nItems;

	}

	// MonsterWorld를 화면에 출력하는 함수
	void Print() {

		// canvas 클래스의 Clear 함수를 이용하여 캔버스 초기화한다.
		canvas.Clear();

		// 반복문을 이용하여 canvas 클래스의 Draw 함수를 이용하여 캔버스의 초기화 된 값을 ■ 문자로 바꾼다.
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				if (Map(x, y) > 0) canvas.Draw(x, y, "■");
			}
		}

		// 반복문을 이용하여 Monster 클래스의 Draw 함수를 이용하여 몬스터를 캔버스에 출력한다.
		for (int i = 0; i < nMon; i++) pMon[i]->Draw(canvas);
		canvas.Print("[ Monster World (Dynamic World) ]");

		// 전체 이동 수와 남은 아이템 수를 출력한다.
		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;

		// Monster 클래스의 Print 함수를 이용하여 몬스터의 정보를 출력한다.
		for (int i = 0; i < nMon; i++) pMon[i]->Print();

		// 전체 몬스터의 수를 출력한다.
		Monster::printCount();
	}

public:

	// MonsterWorld class의 생성자
	// 캔버스의 크기와 총 움직인 회수, 현재 몬스터 수를 초기화한다.
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {

		nMon = 0;
		nMove = 0;

		// 반복문을 이용하여 몬스터 월드의 모든 위치에 아이템이 있도록 1를 저장한다.
		for (int y = 0; y < yMax; y++) {
			for (int x = 0; x < xMax; x++) {
				Map(x, y) = 1;
			}
		}
	}
	// MonsterWorld Class의 소멸자
	// 동적으로 생성되었던 몬스터들을 해제한다.
	~MonsterWorld() { 
		for (int i = 0; i < nMon; i++) {
			delete pMon[i];
		}
	}

	// MonsterWorld에 몬스터를 추가하는 함수
	// 총 몬스터의 수가 상수로 설정한 값보다 적으면 몬스터를 저장하는 mon 배열에 몬스터를 추가한다.
	void Add(Monster* m) { if (nMon < MAXMONS) pMon[nMon++] = m; }

	// 몬스터의 에너지 레벨을 검사하는 함수
	void checkStarvation() {
		
		// 반복문을 이용하여 몬스터들의 에너지를 검사한다.
		for (int i = 0; i < nMon; i++) {

			// 에너지가 0보다 작거나 같은 경우에 동적 할당을 해제한다.
			if (pMon[i]->getEnergy() <= 0) {
				
				// 해당 몬스터 인덱스에 nMon - 1번째에 있는 몬스터 정보를 저장한다.
				pMon[i]->clone(pMon[nMon - 1]);
				// 이후 nMon - 1번째 배열의 동적 할당을 해제한다.
				delete pMon[nMon - 1];
				// 몬스터 마릿수를 감소시키고 반복문을 탈출한다.
				nMon--;
				break;
			}
		}

	}

	// 게임이 진행되는 함수
	// 움직이는 회수의 최대 값과, 지연시간을 매개변수로 받는다.
	void Play(int maxwalk, int wait) {
		
		// MonsterWorld를 출력한다. 
		Print();
		cerr << " 엔터를 누르세요...";
		getchar();

		// 반복문을 이용하여 몬스터를 이동하고 화면을 갱신하는 과정을 진행한다.
		for (int i = 0; i < maxwalk; i++) {
			// 반복문과 Monster 클래스의 Move 함수를 이용하여 몬스터를 움직인다.
			for (int k = 0; k < nMon; k++) {
				pMon[k]->Move(world.Data(), xMax, yMax);
			}

			// 총 움직이는 회수를 증가시키고, 화면을 갱신하여 출력한다.
			nMove++;
			Print();
			// 몬스터의 수가 0이 되면 게임을 종료한다.
			if (nMon == 0) break;
			// 몬스터의 에너지를 검사한다.
			checkStarvation();
			// 게임 종료 조건을 검사한다.
			if (isDone()) break;
			// Sleep 함수를 이용하여 화면이 빨리 움직이는 것을 방지한다.
			Sleep(wait);
		}

	}

};
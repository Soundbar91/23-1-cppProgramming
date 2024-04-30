#pragma once // 해당 헤더 파일이 한번만 빌드되도록 한다.
#include "Canvas.h"
#include "Point.h"
// 맵의 크기를 상수로 선언
#define DIM 40

// 게임에서 사용 될 Monster Class 선언
class Monster {

// 상속을 하기 위해 기존 private의 멤버 변수 및 함수를 protected의 멤버 변수 및 함수로 선언
protected:

	// 몬스터의 이름, 출력 모습, 먹은 아이템의 개수 그리고 에너지를 저장하기 위해 변수 선언
	string Name, icon;
	int nItem, nEnergy;
	// 현재위치(p)와 이전 위치(q)를 저장하는 Point 클래스 객체 선언
	Point q, p;
	// 몬스터가 쉬어야 하는 횟수를 저장할 변수 선언
	int nSleep;
	// 몬스터가 쉬고 난 다음 움직인 거리를 저장할 변수 선언
	double dist;
	// 몬스터가 움직인 총 거리를 저장할 변수 선언
	double total;

	// 몬스터의 위치를 조정해주는 함수
	// Point.h에 정의된 함수 호출 연산자를 이용한다.
	void Clip(int maxx, int maxy) { p(maxx, maxy); }

	// 몬스터가 아이템을 먹는 함수
	void Eat(int** Map) {

		// 조건문을 이용해서 아이템 여부 확인
		// 아이템이 있다면 해당 위치의 값을 변경하여 아이템이 없도록 한다.
		// 먹은 아이템의 개수와 에너지를 증가 시킨다.
		if (Map[p.y][p.x] == 1) {
			Map[p.y][p.x] = 0;
			nItem++;
			nEnergy += 8;
		}
		// 만약 움직인 좌표에 아이템이 없고 에너지의 최솟값보다 큰 상태이면, 에너지를 감소시킨다.
		else if (Map[p.y][p.x] != 1 && nEnergy > 0) {
			// 에너지가 음수가 출력되는 상황을 방지한다.
			if (nEnergy - 5 < 0) nEnergy = 0;
			else nEnergy -= 5;
		}
		
		// Point 클래스의 이항 연산자 -와 형 변환 연산자를 사용하여 dist와 total 변수에 움직인 거리 만큼 값을 증가시킨다.
		dist += (double)(p - q);
		total += (double)(p - q);
		// 현재 위치를 이전 위치에 복사한다.
		q = p;

		// dist의 값이 0 이상이면 몬스터가 쉬도록 한다.
		if (dist > 20) {
			dist = 0;
			nSleep = 10;
		}

	}

	// 몬스터가 쉬고 있는 상태인지를 검사하는 함수
	bool isSleep() {

		// 쉬고 있는 상태이면 nSleep를 하나 줄여주고 true를 반환한다.
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		// 쉬고 있지 않는 상태가 아니면 false를 반환한다.
		else return false;

	}

public:
	// 몬스터의 수를 나타내는 정적 멤버 변수 추가
	static int nMonster;

	// Monster class의 생성자
	// 몬스터의 이름, 출력 화면, 생성 위치를 매개 변수로 받아 설정한다.
	// 아이템과 에너지는 0과 100으로 초기화한다.
	// 몬스터가 생성될 때 마다 몬스터의 수를 증가시켰다.
	Monster(string n = "나괴물", string i = "※", int x = 0, int y = 0) : Name(n), icon(i), q(x,y), p(x,y), nSleep(0), dist(0.0),total(0.0), nItem(0), nEnergy(100) {
		Monster::nMonster++;
	}
	// Monster class의 가상 소멸자
	virtual ~Monster() {

		// 에너지의 값에 따라 출력하는 문구를 다르게 설정하였다.
		// 몬스터가 죽을 때마다 몬스터의 수를 감소시켰다.
		if (nEnergy <= 0) {
			cout << Name << icon << " 굶어죽었습니다~~~~\n";
			Monster::nMonster--;
		}
		else if (nEnergy > 0){
			cout << Name << icon << " 물러갑니다~~~\n";
			Monster::nMonster--;
		}

	}

	// 몬스터를 Canvas에 출력하는 함수
	// canvas 클래스의 Draw 함수에 몬스터의 위치와 출력 화면을 넘겨 화면에 출력한다.
	void Draw(Canvas& canvas) { canvas.Draw(p[0], p[1], icon); }

	// 몬스터 에너지를 반환하는 함수
	int getEnergy() { return nEnergy; }

	// 전체 몬스터 수를 출력하는 정적 멤버 함수
	static void printCount() { printf(" 전체 몬스터의 수 : %d\n", Monster::nMonster); }

	// 몬스터를 무작위로 움직이는 함수
	// 가상 함수로 선언
	virtual void Move(int** Map, int maxx, int maxy) {

		// 쉬고 있지 않는 경우에만 이동을 진행한다. 
		if (!isSleep()) {
			int num = rand() % 9 + 1;
			p += Point(num % 3 - 1, num / 3 - 1);

			// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
			// 아이템이 있는지 확인하여 아이템을 먹는다.
			Clip(maxx, maxy);
			Eat(Map);

		}
		
	}

	// 몬스터의 정보를 출력하는 함수
	// 몬스터의 이름, 출력 화면, 먹은 아이템의 개수 그리고 에너지 상태를 출력
	void Print() { cout << "\t" << Name << icon << ":" << nItem << " E:" << nEnergy <<  endl; }

};
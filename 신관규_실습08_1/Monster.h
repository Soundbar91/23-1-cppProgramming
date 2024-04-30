#pragma once // 해당 헤더 파일이 한번만 빌드되도록 한다.
#include "Canvas.h"
// 맵의 크기를 상수로 선언
#define DIM 40

// 게임에서 사용 될 Monster Class 선언
class Monster {

private:

	// 몬스터의 이름, 출력 모습, 현재 위치, 먹은 아이템의 개수 그리고 에너지를 저장하기 위해 private 멤버 변수로 선언
	string Name, icon;
	int x, y, nItem, nEnergy;

	// 몬스터의 위치를 조정해주는 함수
	void Clip(int maxx, int maxy) {

		// 조건문을 이용하여 몬스터의 좌표를 검사
		// 몬스터가 맵 밖으로 나가게 되면 위치를 조정해준다
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;

	}

	// 몬스터가 아이템을 먹는 함수
	void Eat(int** Map) {

		// 조건문을 이용해서 아이템 여부 확인
		// 아이템이 있다면 해당 위치의 값을 변경하여 아이템이 없도록 한다.
		// 먹은 아이템의 개수와 에너지를 증가 시킨다.
		if (Map[y][x] == 1) {
			Map[y][x] = 0;
			nItem++;
			nEnergy += 8;
		}
		// 만약 움직인 좌표에 아이템이 없고 에너지의 최솟값보다 큰 상태이면, 에너지를 감소시킨다.
		else if (Map[y][x] != 1 && nEnergy > 0) {
			// 에너지가 음수가 출력되는 상황을 방지한다.
			if (nEnergy - 5 < 0) nEnergy = 0;
			else nEnergy -= 5;
		}

	}

public:
	// 몬스터의 수를 나타내는 정적 멤버 변수 추가
	static int nMonster;

	// Monster class의 생성자
	// 몬스터의 이름, 출력 화면, 생성 위치를 매개 변수로 받아 설정한다.
	// 아이템과 에너지는 0과 100으로 초기화한다.
	// 몬스터가 생성될 때 마다 몬스터의 수를 증가시켰다.
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0) : Name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {
		Monster::nMonster++;
	}
	// Monster class의 소멸자
	~Monster() {

		// 에너지의 값에 따라 출력하는 문구를 다르게 설정하였다.
		// 몬스터가 죽을 때마다 몬스터의 수를 감소시켰다.
		if (nEnergy <= 0) {
			printf("Monster 하나가 굶어죽습니다.\n");
			Monster::nMonster--;
		}
		else if (nEnergy > 0){
			cout << "\t" << Name << icon << " 물러갑니다~~~\n";
			Monster::nMonster--;
		}

	}

	// 몬스터를 Canvas에 출력하는 함수
	// canvas 클래스의 Draw 함수에 몬스터의 위치와 출력 화면을 넘겨 화면에 출력한다.
	void Draw(Canvas& canvas) { canvas.Draw(x, y, icon); }

	// 몬스터 에너지를 반환하는 함수
	int getEnergy() { return nEnergy; }

	// 전체 몬스터 수를 출력하는 정적 멤버 함수
	static void printCount() { printf(" 전체 몬스터의 수 : %d\n", Monster::nMonster); }

	// 몬스터를 무작위로 움직이는 함수
	void Move(int** Map, int maxx, int maxy) {

		// switch-case을 이용하여 난수의 경우에 따라 몬스터를 옮긴다.
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

		// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
		// 아이템이 있는지 확인하여 아이템을 먹는다.
		Clip(maxx, maxy);
		Eat(Map);

	}

	// 몬스터 정보를 깊은 복사를 하는 함수
	void clone(Monster* a) {

		// 매개변수로 받은 몬스터 객체의 정보를 저장한다.
		Name = a->Name;
		icon = a->icon;
		x = a->x;
		y = a->y;
		nItem = a->nItem;

		// 소멸자에서 에너지의 정보에 따라 출력하는 문구가 다르도록 설정하였다.
		// 마지막 배열의 동적 할당이 해제될 때 굶어죽었다라는 문구를 출력하기 위해 에너지의 값을 서로 바꿨다.
		// 나머지 정보까지는 바꿀 필요가 없다고 생각되어 값을 대입 연산자를 이용해서 저장만 했다.
		int _nEnergy = nEnergy;
		nEnergy = a->nEnergy;
		a->nEnergy = _nEnergy;

	}

	// 몬스터의 정보를 출력하는 함수
	// 몬스터의 이름, 출력 화면, 먹은 아이템의 개수 그리고 에너지 상태를 출력
	void Print() { cout << "\t" << Name << icon << ":" << nItem << " E:" << nEnergy <<  endl; }

};
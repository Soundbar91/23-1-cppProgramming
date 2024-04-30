#pragma once // 해당 헤더 파일이 한번만 빌드되도록 한다.
#include "Monster.h"
#include <Windows.h>

// 몬스터 클래스의 상속을 받은 좀비 클래스
class Zombie : public Monster {

public:
	// 좀비 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치를 매개 변수로 받아 몬스터 클래스를 초기화한다.
	Zombie(string n = "허접좀비", string i = "§", int x = 0, int y = 0) : Monster(n, i , x, y) {}
	// 좀비 클래스의 소멸자이며 문자를 출력한다.
	~Zombie() { cout << " Zombie"; }
};

// 몬스터 클래스의 상속을 받은 뱀파이어 클래스
class Vampire : public Monster {

public:
	// 뱀파이어 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치를 매개 변수로 받아 몬스터 클래스를 초기화한다.
	Vampire(string n = "뱀파이어", string i = "★", int x = 0, int y = 0) : Monster(n, i, x, y) {}
	// 좀비 클래스의 소멸자이며 문자를 출력한다.
	~Vampire() { cout << " Vampire"; }

	// 뱀파이어 클래스에서 재정의 된 Move 함수이다.
	void Move(int** map, int maxx, int maxy) {

		// 난수를 0 ~ 3까지 발생을 시킨다.
		int dir = rand() % 4;

		// 난수의 값에 따라 상하좌우로만 움직이도록 한다.
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;

		// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
		// 아이템이 있는지 확인하여 아이템을 먹는다.
		Clip(maxx, maxy);
		Eat(map);
	}
};

// 몬스터 클래스의 상속을 받은 처녀 귀신 클래스
class KGhost : public Monster {

public:
	// 처녀귀신 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치를 매개 변수로 받아 몬스터 클래스를 초기화한다.
	KGhost(string n = "처녀귀신", string i = "♥", int x = 0, int y = 0) : Monster(n, i, x, y) {}
	// 처녀귀신 클래스의 소멸자이며 문자를 출력한다.
	~KGhost() { cout << " KGhost"; }

	// 처녀귀신 클래스에서 재정의 된 Move 함수이다.
	void Move(int** map, int maxx, int maxy) {

		// 최대로 움직일 수 있는 값까지 난수를 발생시켜 어디든지 이동할 수 있도록 한다.
		x = rand() % maxx;
		y = rand() % maxy;

		// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
		// 아이템이 있는지 확인하여 아이템을 먹는다.
		Clip(maxx, maxy);
		Eat(map);
	}
};

// 몬스터 클래스의 상속을 받은 스몸비 귀신 클래스
class Smombi : public Monster {

	// 오른쪽 대각선으로 움직일 것인지, 왼쪽 대각선으로 움직일 것인지 판단하기 위한 bool 변수 선언
	bool Dir;

public:

	// 스몸비 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치, 이동 방향을 매개 변수로 받아 몬스터 클래스를 초기화한다.
	Smombi(string n = " 대각좀비", string i = "↗", int x = 0, int y = 0, bool dir = true) : Monster(n, i, x, y), Dir(dir) {}
	// 스몸비 클래스의 소멸자이며 문자를 출력한다.
	~Smombi() { cout << " Smobi"; }

	// 스몸비 클래스에서 재정의 된 Clip 함수
	void Clip(int maxx, int maxy) {

		// 오른쪽 대각선으로 만 이동하는 몬스터에 대한 위치 조정
		if (Dir) {

			if (x >= maxx) {
				x -= 1;

				if (y < 0) y = 0;
				else y++;
			}

			if (y >= maxy) {
				y -= 1;

				if (x < 0) x = 0;
				else x++;
			}

			if (y < 0) x -= 1, y = 0;
			if (x < 0) x = 0, y -= 1;

		}

		// 왼쪽 대각선으로 만 이동하는 몬스터에 대한 위치 조정
		else {

			int Try = 0;

			if (x >= maxx) x--, y--, Try = 1;

			if (x < 0) {
				x = 0;

				if (y < 0) y = 0;
				else y++;
			}

			if (y >= maxy) if (Try == 0) y--, x--;

			if (y < 0) {
				y = 0;

				if (x < 0) x = 0;
				else x++;
			}

		}
	}

	// 스몸비 클래스에서 재정의 된 Move 함수
	void Move(int** map, int maxx, int maxy) {

		// 난수를 발생시켜 0이면 올라가고 1이면 내려간다.
		int Way = rand() % 2;

		// 오른쪽 대각선으로만 움직이는 몬스터를 이동시키는 조건문
		if (Dir) {

			// 발생시킨 난수의 값을 0이면 올라가고 1이면 내려가도록 몬스터를 움직인다.
			x += ((Way == 0) ? 1 : -1);
			y += ((Way == 0) ? -1 : 1);

		}
		// 왼쪽 대각선으로만 움직이는 몬스터를 이동시키는 조건문
		else {

			// 발생시킨 난수의 값을 0이면 올라가고 1이면 내려가도록 몬스터를 움직인다.
			x += ((Way == 0) ? -1 : 1);
			y += ((Way == 0) ? -1 : 1);

		}

		// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
		// 아이템이 있는지 확인하여 아이템을 먹는다.
		Clip(maxx, maxy);
		Eat(map);

	}

};

// 몬스터 클래스의 상속을 받은 코룡 클래스
class Koryong : public Monster {

public:
	// 코룡 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치를 매개 변수로 받아 몬스터 클래스를 초기화한다.
	Koryong(string n = "코룡이이", string i = "◎", int x = 0, int y = 0) : Monster(n, i, x, y) {}
	// 코룡 클래스의 소멸자이며 문자를 출력한다.
	~Koryong() { cout << " Koryong"; }

	// 코룡 클래스에서 재정의된 Move 함수
	void Move(int** map, int maxx, int maxy) {

		// 난수를 0 ~ 3까지 발생을 시킨다.
		int dir = rand() % 4;

		// 난수의 값에 따라 상하좌우로 4칸만 움직이도록 한다.
		if (dir == 0) x -= 4;
		else if (dir == 1) x += 4;
		else if (dir == 2) y -= 4;
		else y += 4;

		// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
		// 아이템이 있는지 확인하여 아이템을 먹는다.
		Clip(maxx, maxy);
		Eat(map);
	}
};

// 몬스터 클래스의 상속을 받은 강시 클래스
class Jiangshi : public Monster {

	// 샹시 클래스에 상속을 하기 위해 움직이는 방향을 판단하는 bool 변수를 protected 멤버 변수로 선언
protected:
	bool bHori;

public:
	// 강시 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치, bool 변수를 매개 변수로 받아 몬스터 클래스를 초기화한다.
	Jiangshi(string n= "대륙강시", string i = "↔", int x = 0, int y = 0, bool bH = true) : Monster(n, i, x, y), bHori(bH) {}
	// 강시 클래스의 소멸자이며 문자를 출력한다.
	~Jiangshi() { cout << " Jiangshi"; }

	// 강시 클래스에서 재정의 된 Move 함수 
	void Move(int** map, int maxx, int maxy) {
		
		// 이동 방향과 점프 범위를 설정하기 위해 난수를 발생시킨다. 
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;

		// bHori가 true면 좌우로만, false이면 상하로만 움직이며, dir의 값에 따라 점프를 뛰는 방향이 달라진다.
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);

		// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
		// 아이템이 있는지 확인하여 아이템을 먹는다.
		Clip(maxx, maxy);
		Eat(map);
	}
};

// 강시 클래스의 상속을 받은 수퍼 강시 클래스
class Siangshi : public Jiangshi {

public:
	// 수퍼 강시 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치, bool 변수를 매개 변수로 받아 몬스터 클래스를 초기화한다.
	Siangshi(string n = "대륙강시", string i = "×", int x = 0, int y = 0, bool bH = true) : Jiangshi(n, i, x, y) {}
	// 수퍼 강시 클래스의 소멸자이며 문자를 출력한다.
	~Siangshi() { cout << " Siangshi"; }

	// 수퍼 강시 클래스에서 재정의 된 Move 함수
	void Move(int** map, int maxx, int maxy) {

		// 방향을 전환하기 위해 시간을 측정
		// 시작 시간을 저장하는 변수는 함수가 실행되는 동안 계속 존재해야하므로 전역 변수로 선언
		static int start = clock();
		// 이동 방향과 점프 범위를 설정하기 위해 난수를 발생시킨다. 
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		// 게임의 진행시간을 측정하기 위해 선언한 변수
		int finish = clock();
		// 게임의 소요시간을 계산하여 저장하는 변수
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;

		// 게임의 소요시간이 10이면 bHori을 바꿔서 몬스터의 움직이는 방향을 바꾼다.
		if ((int)duration == 10) bHori = (bHori == true) ? false : true;
		// bHori가 true면 좌우로만, false이면 상하로만 움직이며, dir의 값에 따라 점프를 뛰는 방향이 달라진다.
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);

		// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
		// 아이템이 있는지 확인하여 아이템을 먹는다.
		Clip(maxx, maxy);
		Eat(map);
	}

};

#pragma once // 해당 헤더 파일이 한번만 빌드되도록 한다.
#include "Monster.h"
#include <conio.h>
// 방향키의 값을 열거형으로 선언한다.
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

// 몬스터의 상속을 받은 휴먼 클래스
class Human : public Monster {

public:
	// 휴먼 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치를 매개 변수로 받아 몬스터 클래스를 초기화한다.
	Human(string n = "미래인류1,", string i = "♀", int px = 0, int py = 0) : Monster(n, i, px, py) {}
	// 휴먼 클래스의 소멸자이며 문자를 출력한다.
	~Human() { cout << "[Huamn]"; }

	// 화살표를 입력는 함수이며 입력받은 키가 화살표이면 화살표 키를 반환한다.
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }

	// 인간 클래스에서 제정의 된 Move 함수
	void Move(int** map, int maxx, int maxy) {

		// 화살표가 입력이 되었으면 이동이 되도록 한다.
		if (_kbhit()) {

			// 쉬고 있지 않는 경우에만 이동을 진행한다.
			if(!isSleep()){
				
				// 입력된 화살표를 저장할 변수를 선언
				char ch = getDirKey();

				// 입력된 화살표에 따라 상하좌우를 움직이도록 한다.
				if (ch == Left) p[0]--;
				else if (ch == Right) p[0]++;
				else if (ch == Up) p[1]--;
				else if (ch == Down) p[1]++;
				else return;

				// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
				// 아이템이 있는지 확인하여 아이템을 먹는다.
				Clip(maxx, maxy);
				Eat(map);
			}

		}
	}
};

// 휴면 클래스의 상속을 받은 Tuman 클래스
class Tuman : public Human {

public:
	// Tuman 클래스의 생성자이며, 몬스터의 이름, 출력 화면, 생성 위치를 매개 변수로 받아 휴먼 클래스를 초기화한다.
	Tuman(string n = "미래인류2,", string i = "♂", int px = 0, int py = 0) : Human(n, i, px, py) {}
	// Tuman 클래스의 소멸자이며 문자를 출력한다.
	~Tuman() { cout << "[Tuamn]"; }

	// Tuman 클래스의 움직임을 위해 새롭게 정의 된 함수
	void Move(int** map, int maxx, int maxy, unsigned char CH) {



		// 화살표를 눌렀을 때 해당 방향으로 움직이도록 한다.
		if (CH == Left) p[0]--;
		else if (CH == Right) p[0]++;
		else if (CH == Up) p[1]--;
		else if (CH == Down) p[1]++;

		// a, d, w, s를 눌렀을 때 해당 방향으로 움직이도록 한다.
		else if (CH == 'a') p[0]--;
		else if (CH == 'd') p[0]++;
		else if (CH == 'w') p[1]--;
		else if (CH == 's') p[0]++;
		else return;
		
		// 움직인 좌표가 맵 외부로 나갔는지 확인하여 위치 조정을 한다.
		// 아이템이 있는지 확인하여 아이템을 먹는다.
		Clip(maxx, maxy);
		Eat(map);

	}

};

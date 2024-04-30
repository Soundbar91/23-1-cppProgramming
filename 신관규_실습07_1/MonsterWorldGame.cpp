#include "MonsterWorld.h"
#include <time.h>

int main() {

	srand((unsigned int)time(NULL));
	// 게임 맵의 크기를 설정하기 위한 변수 선언
	int w = 16, h = 8;

	// MonsterWorld 게임의 맵의 크기를 넘긴다. 
	MonsterWorld game(w, h);

	// Monster 클래스로 몬스터 객체를 선언
	Monster m("몬스터", "※", rand() % w, rand() % h);
	// MonsterWorld 클래스의 Add함수를 이용하여 몬스터를 추가
	game.Add(m);
	// MonsterWorld 클래스의 Add함수에 무명 객체를 이용하여 몬스터를 추가한다.
	game.Add(Monster("도깨비", "§", rand() % w, rand() % h));
	game.Add(Monster("별그대", "★", rand() % w, rand() % h));
	game.Add(Monster("고스트", "♥", rand() % w, rand() % h));
	// MonsterWorld 클래스의 Play 함수에 최대 이동 회수와 지연시간을 넘기면서 게임이 진행이 된다.
	game.Play(100, 10);
	printf("------게임 종료-----------------------\n");

	return 0;

}
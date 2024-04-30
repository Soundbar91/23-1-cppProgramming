#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include "Human.h"
#include <time.h>

int main() {

	srand((unsigned int)time(NULL));
	// 게임 맵의 크기를 설정하기 위한 변수 선언
	int w = 20, h = 10;

	// MonsterWorld 게임의 맵의 크기를 넘긴다. 
	MonsterWorld game(w, h);

	// Monster 클래스로 몬스터 객체를 선언
	// MonsterWorld 클래스의 Add함수에 몬스터를 동적으로 할당해 추가한다.
	game.Add(new Tuman("미래의좌용", "좌", rand() % w, rand() % h));
	game.Add(new Tuman("미래의우용", "우", rand() % w, rand() % h));
	game.Add( new Zombie("허접한좀비", "§", rand() % w, rand() % h));
	game.Add( new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.Add( new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.Add( new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));
	game.Add( new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));
	game.Add( new Smombi("오른쪽좀비", "↗", rand() % w, rand() % h, true));
	game.Add( new Smombi("왼쪽의좀비", "↖", rand() % w, rand() % h, false));
	game.Add( new Siangshi("수퍼강시맨", "×", rand() % w, rand() % h, true));
	game.Add( new Koryong("한기대코룡", "◎", rand() % w, rand() % h));
	// MonsterWorld 클래스의 Play 함수에 최대 이동 회수와 지연시간을 넘기면서 게임이 진행이 된다.
	game.Play(100, 100);
	printf(" 안녕히 가세요!!! 몬스터 월드 !!!\n");

	return 0;

}
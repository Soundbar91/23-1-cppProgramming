#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include "Human.h"
#include "RankingBoard.h"
#include <time.h>

int main() {

	// RankingBoard 클래스의 객체 생성
	RankingBoard rank;

	// 예외가 발생할 수 있으므로 try 블럭에 랭킹 파일을 불러오는 함수를 포함하였다.
	try {
		rank.load("MonsterWorld.rnk");
	}
	// 파일이 존재하지 않을 경우 예외가 발생하기 때문에 이를 처리하기 위한 catch 블럭
	catch (FileException e) {

		// 입력한 비밀번호와 실제 비밀번호를 저장할 문자열 배열을 선언했다.
		char str[80];
		string passwd, correct = "123456";

		cout << "관리자 비밀번호를 입력하세요: ";
		// 반복문을 통해 사용자로 부터 비밀번호를 입력 받는다.
		for (int i = 0;; i++) {
			// _getch 함수를 이용하여 비밀번호를 입력받고 putchar를 이용하여 숫자가 아닌 임의의 문자가 출력한다.
			str[i] = _getch();
			putchar('*');
			// 다음줄로 넘어가게 되면 str 배열에 저장된 비밀번호를 passwd에 저장하고 반복문을 탈출한다.
			if (str[i] == '\r') {
				str[i] = '\0';
				passwd = str;
				cout << "\n";
				break;
			}
		}
		// 만약 비밀번호가 틀리면 게임이 종료가 된다.
		if (passwd != correct) {
			cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
			exit(0);
		}
	}
	// 현재의 랭킹을 화면에 출력한다.
	rank.print("[게임 랭킹: 시작]");

	srand((unsigned int)time(NULL));
	// 게임 맵의 크기를 설정하기 위한 변수 선언
	int w = 20, h = 10;

	// MonsterWorld 게임의 맵의 크기를 넘긴다. 
	MonsterWorld game(w, h);

	// Monster 클래스로 몬스터 객체를 선언
	// MonsterWorld 클래스의 Add함수에 몬스터를 동적으로 할당해 추가한다.

	Tuman* human_1 = new Tuman("미래의좌용", "좌", rand() % w, rand() % h);
	game.Add(human_1);
	Tuman* human_2 = new Tuman("미래의우용", "우", rand() % w, rand() % h);
	game.Add(human_2);
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
	game.Play(30, 100);
	printf("--------- 게임 종료 -------------\n");

	// 입력한 비밀번호와 실제 비밀번호를 저장할 문자열 배열을 선언했다.
	char str[80];
	string passwd, correct = "123456";

	cout << "관리자 비밀번호를 입력하세요: ";
	// 반복문을 통해 사용자로 부터 비밀번호를 입력 받는다.
	for (int i = 0;; i++) {
		// _getch 함수를 이용하여 비밀번호를 입력받고 putchar를 이용하여 숫자가 아닌 임의의 문자가 출력한다.
		str[i] = _getch();
		putchar('*');
		// 다음줄로 넘어가게 되면 str 배열에 저장된 비밀번호를 passwd에 저장하고 반복문을 탈출한다.
		if (str[i] == '\r') {
			str[i] = '\0';
			passwd = str;
			cout << "\n";
			break;
		}
	}
	// 만약 비밀번호가 틀리면 게임이 종료가 된다.
	if (passwd != correct) {
		cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
		exit(0);
	}

	// 사용자로부터 랭킹을 저장할 파일명을 입력받는다.
	string Filename;
	printf("저장할 파일명을 입력하세요 : ");
	cin >> Filename;

	// 예외가 발생할 수 있으므로 try 블럭에 입력받은 파일을 불러오는 함수를 포함하였다.
	try {
		rank.load(Filename);
	}
	// 파일이 존재하지 않을 경우 예외가 발생하기 때문에 이를 처리하기 위한 catch 블럭
	catch (FileException e) {
		printf("파일이 존재하지 않습니다. 새로 생성합니다.\n\n");
	}

	// 왼쪽 플레이어와 오른쪽 플레이어의 아이템 획득 수와 이동거리당 아이템 수를 매개변수로 전달하여 랭킹을 갱신한다.
	printf("왼쪽 플레이어 랭킹 등록");
	rank.add(human_1->nItem, human_1->nItem / human_1->total);
	printf("\n오른쪽 플레이어 랭킹 등록");
	rank.add(human_2->nItem, human_2->nItem / human_2->total);
	// 현재의 랭킹을 화면에 출력한다.
	rank.print("[게임 랭킹 : 종료]");
	// 랭킹을 파일에 저장한다.
	rank.store(Filename);
	rank.store("MonsterWorld.rnk");

	return 0;

}
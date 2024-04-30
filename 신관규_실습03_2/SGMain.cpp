#include "SpeedGame.h"

void main() {

	// 난수 생성기에 대한 시작 시드 값을 설정
	srand((unsigned)time(NULL));

	// 문제의 수 10과 사용자로부터 입력 받을 숫자를 저장할 변수 선언
	int nPlay = 10;
	int Num = 0;

	// 사용자로부터 숫자를 입력 받아, 어떤 게임을 할 것인지 선택
	printf(" 게임을 선택하시오.\n");
	printf(" 1 : 구구단, 2 : 두 자리수 곱셈, 3 ~ 9 : 3 ~ 9 자리 수 덧셈 == > ");
	scanf_s("%d", &Num);
	getchar();
	system("cls");
	
	if (Num == 1) printf("[스피드 구구단 게임]\n\n");
	else if (Num == 2) printf("[스피드 두 자리수 곱셈 게임]\n\n");
	else printf("[스피드 %d자리 덧셈 게임]\n\n", Num);
	
	printf(" %d번 테스트 하겠습니다.\n", nPlay);
	printf(" 크게 심소흡을 하시고...\n 준비되면 엔터를 누르세요...");
	getchar();
	system("cls");

	// 1번을 입력하면 구구단이 실행
	if (Num == 1) playSpeedGugu(nPlay);
	// 2번을 입력하면 스피드 두 자리수 곱셈 게임이 실행
	else if (Num == 2) playMultiplication(nPlay);
	// 그 외의 숫자를 입력하면 해당 숫자의 자리수 게임이 실행
	else playSpeedAddition(nPlay, Num);

}
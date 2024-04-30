#include "noWarGame.h"

void main() {
	
	// 플레이어 수, 총의 발수, 총알의 개수를 저장할 변수를 선언
	int nTurn, nGun, nBullets = 0;
	// 난수 생성기에 대한 시작 시드 값을 설정
	srand((unsigned)time(NULL));

	// 플레이어 수, 총의 발수, 총알의 개수를 사용자로부터 입력을 받는다.
	printf("게임 인원을 입력하시오 ( 예 : 2 ) == > ");
	scanf_s("%d", &nTurn);
	printf("몇 연발 총을 사용 할 것인지 입력하시오 == > ");
	scanf_s("%d", &nGun);
	printf("사용할 총알의 개수를 입력하시오 (%d 미만) == > ", nGun);
	scanf_s("%d", &nBullets);
	getchar();

	// 러시안룰렛 함수 호출
	playRussianRoulette( nTurn , nGun , nBullets);
	printf("게임이 종료됐습니다.");

}
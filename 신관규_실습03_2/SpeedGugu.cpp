#include "SpeedGame.h"

// SpeedGugu.cpp에서만 사용 가능한 전역변수 선언
static int NumGames = 0;
static int NumWins = 0;
static double Score = 0;
static double tElapsed = 0;

// 구구단을 출력하는 함수, 참과 거짓을 리턴하기 위해 bool로 함수를 선언
static bool playGuguOnce() {

	// rand를 이용하여 숫자의 범위를 2 ~ 9로 제한한하여 난수를 발생
	// 이를 저장하는 변수 2개와 결과값을 저장할 변수 선언
	int Dan = rand() % 8 + 2;
	int Weight = rand() % 8 + 2;
	int Result = 0;

	// 문제가 나올 때 마다, NumGames를 증가시켜 게임 횟수를 카운트한다
	NumGames++;
	printf("[문제%2d] : %2d x %2d = ", NumGames, Dan, Weight);
	scanf_s("%d", &Result);
	// 만약, 정답이면 NumWins를 증가시켜 맞힌 문제의 수를 카운트한다
	if (Result == Dan * Weight) NumWins++;
	// 정답을 맞췄으면 1를 리턴 값으로, 틀렸으면 0을 리턴 값으로 준다.
	return (Result == Dan * Weight);

}

// 구구단 함수를 호출하면서 시간을 측정
void playSpeedGugu(int nPlay) {
	
	// 시간 측정을 시작하는 위치
	clock_t t0 = clock();
	
	// 반복문을 이용하여 구구단 함수를 호출하여 문제를 푼다.
	for (int i = 0; i < nPlay; i++) {
		if (playGuguOnce() == false) printf("\t틀렸습니다.\n");
	}

	// 시간 측정을 종료하는 위치
	clock_t t1 = clock();
	// 초 단위로 변환
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;
	
	// 맞힌 횟수가 게임의 수보다 적으면 점수는 0, 그렇지 않으면 점수를 계산하여 Score 변수에 저장
	Score = (NumGames > NumWins) ? 0.0 : 100 * (5.0 * NumGames - tElapsed) / (5.0 * NumGames);

	printf("\n점수 = %4.1f점 ( 총 %4.1f초 )\n", Score, tElapsed);
}
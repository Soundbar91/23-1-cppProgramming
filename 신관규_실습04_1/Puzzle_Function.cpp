#include "Ranking.h"

// 방향키의 값을 열거형으로 선언한다.
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

// 열거형으로 저장한 방향키의 값을 정수형 배열에 선언
static int DirKey[4] = { Left, Right, Up, Down };
// 퍼즐 게임의 숫자들이 저장 될 2차원 배열 선언
static int Map[6][6];
// 현재 좌표를 저장할 정수형 변수 선언
static int X, Y;
// 움직인 횟수를 저장할 변수 선언
static int nMove;
// 게임이 시작되는 시간
static clock_t tStart;
// 리플레이를 위해 선언한 3차원 배열
static int Re_Map[300][6][6];
// 중간에 게임의 정보를 저장하기 위한 변수 선언
static int Save_input = 0;
// 게임의 크기를 저장하기 위한 변수 선언
int NUM = 0;

// 배열을 초기화 하는 함수
static void init() {

	// 반복문을 이용해서 모든 퍼즐 조각을 제자리로 보낸다.
	for (int i = 0; i < NUM * NUM - 1; i++) Map[i / NUM][i % NUM] = i + 1;
	Map[NUM - 1][NUM - 1] = 0;
	X = NUM - 1; Y = NUM - 1;

	// 기준 시각과 이동 횟수를 초기화한다.
	srand(time(NULL));
	tStart = clock();
	nMove = 0;

}

// 퍼즐 출력 함수
static void Display() {

	system("cls");
	printf("\tFifteen Puzzle\n\t");
	printf("--------------\n\t");
	// 반복문을 이용해서 배열에 저장된 퍼즐 숫자들을 출력한다.
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
			if (Map[i][j] > 0) printf("%3d", Map[i][j]);
			else printf("");
		}
		printf("\n\t");
	}
	printf("--------------\n\t");

	// 실시간으로 소요 시간과 이동 횟수를 출력
	clock_t t1 = clock();
	double Time = (double)(t1 - tStart) / CLOCKS_PER_SEC;

	printf("\n\t이동 횟수 : %6d\n\t소요 시간 : %6.1f\n\n", nMove, Time);
}

// 게임 정보를 중간에 저장하는 함수
void Save_Map(int nMove, double Time) {

	// 이진파일로 퍼즐게임 맵을 저장
	FILE* fp;
	fopen_s(&fp, "SaveFile.bin", "w");
	fwrite(&Map, sizeof(Map), 1, fp);
	fclose(fp);

	// 이진파일로 퍼즐 게임판의 크기를 저장한다
	FILE* fp_1;
	fopen_s(&fp_1, "Save_Map_Num.bin", "w");
	fwrite(&NUM, sizeof(int), 1, fp_1);
	fclose(fp_1);

	// 이진파일로 이동 횟수를 저장한다.
	FILE* fp_2;
	fopen_s(&fp_2, "Save_Move.bin", "w");
	fwrite(&nMove, sizeof(int), 1, fp_2);
	fclose(fp_2);

	// 이진파일로 소요 시간을 저장한다.
	FILE* fp_3;
	fopen_s(&fp_3, "Save_TIme.bin", "w");
	fwrite(&Time, sizeof(double), 1, fp_3);
	fclose(fp_3);

}

// 방향키를 입력받아 퍼즐을 움직이는 함수
static bool Move(int Dir) {

	// 각 방향키들이 입력을 받았을 때, 경계 조건을 검사하여 이동할 수 있는지 없는지를 확인한다.
	if (Dir == Right && X > 0) {
		// 맨 왼쪽 열인지 검사하여, 이동이 가능하다면 값을 옮긴다.
		Map[Y][X] = Map[Y][X - 1];
		Map[Y][--X] = 0;
	}
	else if (Dir == Left && X < NUM - 1) {
		// 맨 오른쪽 열인지 검사하여, 이동이 가능하다면 값을 옮긴다.
		Map[Y][X] = Map[Y][X + 1];
		Map[Y][++X] = 0;
	}
	else if (Dir == Up && Y < NUM - 1) {
		// 맨 아래 행인지 검사하여, 이동이 가능하다면 값을 옮긴다.
		Map[Y][X] = Map[Y + 1][X];
		Map[++Y][X] = 0;
	}
	else if (Dir == Down && Y > 0) {
		// 맨 윗 행인지 검사하여, 이동이 가능하다면 값을 옮긴다.
		Map[Y][X] = Map[Y - 1][X];
		Map[--Y][X] = 0;
	}
	// q를 눌러 저장을 할 수 있게함.
	else if (Dir == 113) {
		Save_input += 1;
		return true;
	}
	// 이동에 실패했다면, false를 반환한다.
	else return false;

	// 이동이 성공적으로 됐다면, 이동 횟수를 늘리고 true를 반환한다.
	nMove++;
	return true;
}

// 리플레이를 저장하는 함수
void Recoard() {

	// 3차원으로 선언된 배열에 2차원 퍼즐 게임 맵을 저장한다.
	// 이동이 됐다면, nMove의 값이 증가하고, 이에 따른 3차원 배열에 2차원 퍼즐 게임 맵을 저장한다.
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
				Re_Map[nMove][i][j] = Map[i][j];
		}
	}

}

// 리플레이를 보여주는 함수
void RePlay() {

	// 반복문을 이용하여 3차원 배열을 출력한다.
	for (int i = 0; i < nMove; i++) {
		system("cls");
		printf("\tFifteen Puzzle\n\t");
		printf("--------------\n\t");
		for (int j = 0; j < NUM; j++) {
			for (int k = 0; k < NUM; k++) {
				if (Re_Map[i][j][k] > 0) printf("%3d", Re_Map[i][j][k]);
				else printf("");
			}
			printf("\n\t");
		}
		printf("--------------\n\t");
	}
	printf("엔터를 눌러주세요..");
	_getche();

}

// 숫자를 섞는 함수
static void Shuffle(int nShuffle) {

	// Move 함수와 난수를 이용하여 퍼즐을 움직인다.
	for (int i = 0; i < nShuffle; i++) {
		int Key = DirKey[rand() % 4];
		// 만약 Move함수를 이용해서 움직일 수 없다면, 증가한 i를 감소시키고 다시 반복문을 돌린다.
		if (Move(Key) == false) { i--; continue; }
		Display();
		Sleep(50);
	}

}

// 퍼즐이 다 맞춰졌는지 확인하는 함수
static bool isDone() {

	// 반복문을 이용하여 퍼즐이 정확한 위치에 들어갔는지 확인
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
			if (Map[i][j] != i * NUM + j + 1)
				return (i == NUM - 1) && (j == NUM - 1);
		}
	}
	return true;
}

// 방향 키를 받아드리는 함수
static int getDirKey() {
	// 방향키 혹은 'q'를 입력받았았다면 _getche()로 문자를 입력 받고 그렇지 않다면 0을 Move함수에 리턴값으로 준다.
	return ( _getche() == 224 || _getche() == 113 ) ? _getche() : 0;
}

// 퍼즐게임을 시작하는 함수
int PlayFifteenPuzzle(int Num) {

	// 함수로부터 전달받은 매개변수를 NUM에 저장하여 게임의 크기를 정한다.
	NUM = Num;
	// 리플레이 여부를 저장할 변수 선언
	int RePlay_input = 0;

	// 퍼즐 게임의 주 함수
	init();
	Display();
	PrintRanking();
	printf("\n 퍼즐을 섞어주세요 (엔터)...");
	_getche();
	Shuffle(100);
	printf("\n 게임이 시작됩니다...");

	nMove = 0;
	tStart = clock();

	// isDoan 함수를 이용하여 배열이 정상적으로 배치가 됐는지 확인하여 반복문을 돌린다.
	while (!isDone()) {
		Move(getDirKey());
		Recoard();
		Display();
		if (Save_input == 1) break;
	}
	clock_t t1 = clock();

	// 중간에 'q'를 눌러 저장을 하였다면, Save_Map함수를 이용하여 모든 정보를 저장한다.
	if (Save_input == 1) {
		double Save_time = (double)(t1 - tStart) / CLOCKS_PER_SEC;
		Save_Map(nMove, Save_time);
		system("cls");
		printf("\n\n\t\t게임이 저장되었습니다.\n\n");
		printf("\n\n\t\t게임을 종료합니다.\n\n");
		return 0; // 반환 값을 0을 줘 메인함수에 작성된 조건문을 이용하여 게임을 종료시킨다.
	}

	// 리플레이를 출력
	printf(" 리플레이를 보시겠습니까 (1. YES 2. NO) --> ");
	scanf_s("%d", &RePlay_input);
	if (RePlay_input == 1) RePlay();

	// 반환 값으로 움직인 횟수와 시간을 반환
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	return AddRanking(nMove, d);
}
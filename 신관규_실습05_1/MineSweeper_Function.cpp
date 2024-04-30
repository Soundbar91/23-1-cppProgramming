#include "MineSweeper.h"

// 지뢰 맵에서 지뢰가 있는지 없는지를 상수로 표현하고자 열거형으로 선언
enum LabelType { Empty = 0, Bomb = 9 };
// 마스크 맵의 좌표 상태를 상수로 표현하고자 열거형으로 선언
enum MaskType { Hide = 0, Open  = 1, Flag = 2 };

// 지뢰가 설치되는 맵과 숫자가 적히는 마스크 맵을 선언
static int MineMapMask[101][101];
static int MineMapLabel[101][101];
// 맵의 크기와 전체 지뢰의 수를 저장하는 변수 선언
static int nX, nY = 0;
static int nBomb = 0;

// inline 함수로 선언하여 매크로 기능을 하는 함수
// 마스크 맵과 지뢰 맵을 참조자를 이용해 편하게 맵에 접근할 수 있다.
inline int& Mask(int X, int Y) { return MineMapMask[Y][X]; }
inline int& Label(int X, int Y) { return MineMapLabel[Y][X]; }
// 좌표가 범위 내에 있는지, 좌표에 지뢰가 있는지 없는지를 검사하는 매크로 함수를 선언
inline bool isValid(int X, int Y) { return (X >= 0 && X < nX&& Y >= 0 && Y < nY); }
inline bool isBomb(int X, int Y) { return isValid(X, Y) && Label(X, Y) == Bomb; }
inline bool isEmpty(int X, int Y) { return isValid(X, Y) && Label(X, Y) == Empty; }

// 입력받은 좌표를 검사하는 함수
static void Dig(int X, int Y) {

	// 좌표가 범위 내에 있는지, 그리고 입력받은 좌표가 마스크 맵에서 열려 있는지 않는지(값이 1이 아님을) 확인한다.
	if (isValid(X, Y) && Mask(X, Y) != Open) {
		// 마스크 맵의 입력 받은 좌표 위치를 Open으로(값을 1로) 바꾼다.
		Mask(X, Y) = Open;
		// 만약에 입력받은 좌표가 지뢰 맵에서의 값이 0이면, 인접해 있는 8칸의 좌표들을 재귀 함수로 검사한다.
		if (Label(X, Y) == 0) {
			Dig(X - 1, Y - 1);
			Dig(X - 1, Y);
			Dig(X - 1, Y + 1);
			Dig(X, Y - 1);
			Dig(X, Y);
			Dig(X, Y + 1);
			Dig(X + 1, Y - 1);
			Dig(X + 1, Y);
			Dig(X + 1, Y + 1);
		}
	}

}

// 깃발을 설치하는 함수
static void Mark(int X, int Y) {
	// 좌표가 범위내에 있고, 마스크 맵에서 해당 좌표가 오픈이 되지 않은 상태(값이 0)라면 해당 좌표의 값을 Flag(2)로 바꾼다.
	if (isValid(X, Y) && Mask(X, Y) == Hide) Mask(X, Y) = Flag;
}

// 깃발의 개수를 새는 함수
static int getBombCount() {

	// 깃발의 개수를 새서 저장할 변수 선언
	int Count = 0;

	// 반복문을 이용하여 마스크의 맵 상태를 검사하여 깃발이 있는 상태(값이 2)라면 변수를 증가시킨다.
	for (int Y = 0; Y < nY; Y++) {
		for (int X = 0; X < nX; X++) {
			if (Mask(X, Y) == Flag) Count++;
		}
	}

	// 반환값으로 깃발의 개수를 반환한다.
	return Count;
}

// 지뢰 게임 맵을 출력하는 함수
static void Print() {

	system("cls");
	printf(" 발견 : %2d 전체 : %2d\n", getBombCount(), nBomb);
	printf("  ");
	// 반복문을 이용하여 열의 숫자를 출력한다.
	for (int i = 0; i < nX; i++) printf(" %2d", i);
	printf("\n");
	// 반복문을 이용하여 행의 숫자를 출력한다.
	for (int Y = 0; Y < nY; Y++) {
		printf("%2d ", Y);
		// 반복문을 이용하여 마스크 맵을 출력한다.
		// 이때 inline함수를 이용하여 마스크 맵 좌표의 상태(값)에 따라 출력을 달리한다.
		for (int X = 0; X < nX; X++) {
			if (Mask(X, Y) == Hide) printf(" □");
			else if (Mask(X, Y) == Flag) printf(" ¤");
			else {
				// 좌표를 검사했을 때 폭탄이 있다면 조건문이 참이 되기 때문에 폭발하게 된다.
				// 그 이외에 상황에서는 지뢰 맵을 출력한다.
				// 가시성을 위해 지뢰 맵에서 지뢰가 없는 칸은 @를 출력하였다.
				if (isBomb(X, Y)) printf(" ※");
				else if (isEmpty(X, Y)) printf("  @");
				else printf(" %2d", Label(X, Y));
			}
		}
		printf("\n");
	}

}

// 입력받은 좌표의 인접 8칸에 있는 지뢰의 수를 새는 함수
static int CountNberBombs(int X, int Y) {
	
	// 지뢰의 수를 새서 저장할 변수 선언
	int Count = 0;

	// 반복문을 이용하여 입력받은 좌표의 8칸을 검사한다.
	for (int YY = Y - 1; YY <= Y + 1; YY++) {
		for (int XX = X - 1; XX <= X + 1; XX++) {
			// 만약 범위안에 존재하고, 지뢰맵에서 해당 좌표에 폭탄이 있다면(값이 9) 변수를 증가시킨다.
			if (isValid(XX, YY) && Label(XX, YY) == Bomb)
				Count++;
		}
	}

	// 반환 값으로 지뢰의 수를 반환
	return Count;
}

// 맵을 초기화 하는 함수
static void init(int Total, int Size) {
	
	// 입력 받은 맵의 크기를 전역 변수에 저장한다.
	nX = Size; nY = Size;

	srand((unsigned int)time(NULL));

	// 반복문을 이용해서 마스크 맵에는 아무것도 건들지 않았다는 상수를(값이 0), 지뢰 맵에는 0을 저장한다.
	for (int Y = 0; Y < nY; Y++) {
		for (int X = 0; X < nX; X++) {
			Mask(X, Y) = Hide;
			Label(X, Y) = 0;
		}
	}

	// 입력받은 폭탄의 개수를 전역 변수에 저장한다.
	nBomb = Total;

	// 반복문과 난수를 이용하여 지뢰 맵에 지뢰를 무작위로 대입한다.
	for (int i = 0; i < nBomb; i++) {

		int X, Y = 0;

		// 난수로 발생된 자표가 지뢰 맵에서 지뢰가 없을 때까지 반복문을 돌린다.
		do {
			X = rand() % nX;
			Y = rand() % nY;
		} while (Label(X, Y) != Empty);

		// 해당 좌표의 지뢰맵에 폭탄을 설치(값이 9)한다.
		Label(X, Y) = Bomb;
	}

	// 반복문을 이용하여 지뢰 맵에서 지뢰가 없는 좌표들은 인접 8칸의 상태를 점검해서 지뢰의 개수를 적는다.
	for (int Y = 0; Y < nY; Y++) {
		for (int X = 0; X < nX; X++) {
			if (Label(X, Y) == Empty) Label(X, Y) = CountNberBombs(X, Y);
		}
	}

}

// 좌표를 입력받는 함수
static bool getPos(int& X, int& Y) {

	bool isBomb = false;
	int Flag = 0;

	// 사용자로부터 깃발을 설치할 것인지 입력을 받는다.
	printf("깃발을 설치하시겠습니까 (1. YES 2. NO) --> ");
	scanf_s("%d", &Flag);

	// 조건문으로 경우를 나눠서 행와 열을 입력을 받는다.
	if (Flag == 1) {
		isBomb = true;
		int X_ = 0, Y_ = 0;
		printf("열 입력 --> "); 
		scanf_s("%d", &X_);
		printf("행 입력 --> ");
		scanf_s("%d", &Y_);

		X = X_; Y = Y_;
		return isBomb;
	}
	else {
		int X_ = 0, Y_ = 0;
		printf("열 입력 --> ");
		scanf_s("%d", &X_);
		printf("행 입력 --> "); 
		scanf_s("%d", &Y_);

		X = X_; Y = Y_;
		return isBomb;
	}
}

// 게임의 종료 조건을 검사하는 함수
static int CheckDone() {
	
	int Count = 0;
	// 반복문을 이용하여 마스크 맵을 검사한다.
	for (int Y = 0; Y < nY; Y++) {
		for (int X = 0; X < nX; X++) {
			// 마스크 맵에 열리지 않는 칸(값이 1이 아닌)이 있다면 변수를 증가시킨다.
			if (Mask(X, Y) != Open) Count++;
			// 만약 지뢰가 한칸이라도 열려 있으면 -1를 반환한다.
			else if (isBomb(X, Y)) return -1;
		}
	}
	// 증가시킨 변수의 값과 폭탄의 개수와 같다면 1, 아니면 0를 반환한다.
	return (Count == nBomb) ? 1 : 0;
}

// 지뢰 찾기 게임의 주 함수
void playMineSweeper(int Total, int Size) {

	int X, Y, status = 0;
	// 게임 맵을 초기화 및 랭킹을 불러온다.
	init(Total, Size);
	LoadRanking("MineSweeper_Ranking.bin");
	
	// 시작 시간
	clock_t t1 = clock();

	// 반복문을 이용하여 종료 조건을 만족하면 게임이 종료된다.
	do {
		Print();
		// bool 변수로 선언하여 getPost에서 반환하는 참, 거짓을 저장한다.
		// 깃발을 설치하게 되면 반환값이 참이므로 Mark 함수로 넘어간다.
		// 설치를 하지 않으면 Dig 함수로 넘어간다.
		bool isBomb = getPos(X, Y);

		if (isBomb) Mark(X, Y);
		else Dig(X, Y);
		
		// 반복문 마지막에 게임 종료조건을 검사한다.
		status = CheckDone();
	} while (status== 0);

	// 종료 시간
	clock_t t2 = clock();
	double Clear_time = (double)(t2 - t1) / CLOCKS_PER_SEC;

	// 게임이 종료가 되면 성공과 실패를 구분하여 출력한다.
	Print();
	if (status < 0) printf("\n실패 : 지뢰 폭발 !!!\n\n");

	// 성공을 하면 소요 시간을 출력하고 랭킹을 저장한다.
	else {
		printf("\n 성공 : 탐색 성공 !!!\n");
		printf(" 소요 시간 : %6.1f\n", Clear_time);
		AddRanking(nBomb, Clear_time);
	}

}
#include "Ranking.h"
#define _CRT_SECURE_NO_WARNINGS
extern int PlayFifteenPuzzle(int Num);

int main() {

	// 게임의 크기를 입력 받을 변수 선언
	int NUM = 0;

	printf("\n\n\t\t1. 3 X 3\t2. 4 X 4\t3. 5 X 5\n\n");
	printf("\t\t게임을 선택해주세요 --> ");
	scanf_s("%d", &NUM);
	NUM += 2;
	system("cls");

	// 게임의 크기에 따라 랭킹을 저장할 파일을 구분하기 위해 조건문으로 작성
	if (NUM == 3) {
		LoadRanking("3x3_Ranking.bin");
		int Rank = PlayFifteenPuzzle(NUM);
		if (Rank == 0) return 0;
		PrintRanking();
		StoreRanking("3x3_Ranking.bin");
	}
	else if (NUM == 4) {
		LoadRanking("4x4_Ranking.bin");
		int Rank = PlayFifteenPuzzle(NUM);
		if (Rank == 0) return 0;
		PrintRanking();
		StoreRanking("4x4_Ranking.bin");
	}
	else if (NUM == 5) {
		LoadRanking("5x5_Ranking.bin");
		int Rank = PlayFifteenPuzzle(NUM);
		if (Rank == 0) return 0;
		PrintRanking();
		StoreRanking("5x5_Ranking.bin");
	}
	
	return 0;
}
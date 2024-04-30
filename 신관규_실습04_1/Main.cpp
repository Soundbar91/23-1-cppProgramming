#include "Ranking.h"
#define _CRT_SECURE_NO_WARNINGS
extern int PlayFifteenPuzzle(int Num);

int main() {

	// ������ ũ�⸦ �Է� ���� ���� ����
	int NUM = 0;

	printf("\n\n\t\t1. 3 X 3\t2. 4 X 4\t3. 5 X 5\n\n");
	printf("\t\t������ �������ּ��� --> ");
	scanf_s("%d", &NUM);
	NUM += 2;
	system("cls");

	// ������ ũ�⿡ ���� ��ŷ�� ������ ������ �����ϱ� ���� ���ǹ����� �ۼ�
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
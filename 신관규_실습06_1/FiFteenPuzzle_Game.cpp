#include "FifteenPuzzle.h"

int main() {
	
	// FifttenPuzzle.h�� ����� FifteenPuzzle Ŭ������ �ڷ������� �ϴ� ���� ����
	FifteenPuzzle Game;

	// ������ ũ�⸦ �Է� ���� ���� ����
	int NUM = 0;

	// ����ڷκ��� ������ ũ�⸦ �Է� �޴´�.
	printf("\n\n\t\t1. 3 X 3\t2. 4 X 4\t3. 5 X 5\n\n");
	printf("\t\t������ �������ּ��� --> ");
	scanf_s("%d", &NUM);
	NUM += 2;
	system("cls");

	// Game Ŭ���� publice �Լ� Set_Size�� �Է¹��� ������ ũ�⸦ �����Ѵ�.
	Game.Set_Size(NUM);

	// �Է¹��� ������ ũ�⿡ ���� ��ŷ�� ������ �Ǿ�� �ϱ� ������ �ش��ϴ� ũ���� ��ŷ ������ �����Ѵ�.
	if (NUM == 3) Game.Play("3x3_Ranking.bin");
	else if (NUM == 4) Game.Play("4x4_Ranking.bin");
	else if (NUM == 5) Game.Play("5x5_Ranking.bin");

	return 0;

}
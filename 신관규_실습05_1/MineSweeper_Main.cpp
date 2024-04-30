#include "MineSweeper.h"
extern void playMineSweeper(int nBomb, int Size);

void main() {

	// �Է¹��� ������ ������ ���� ũ�⸦ ������ ���� ����
	int Bomb = 0;
	int Num = 0;

	// ��ŷ�� �ҷ��� ����� �Ѵ�.
	LoadRanking("MineSweeper_Ranking.bin");
	printf(" \t\t<Mine Sweeper>\n");
	PrintRanking();
	// ���� ���� ũ��� �ż��� ������ ������ ����ڷκ��� �Է��� �޴´�.
	printf(" ���� �� ũ�⸦ �Է� (100 ����) : ");
	scanf_s("%d", &Num);
	printf(" �ż��� �� ������ ���� �Է� : ");
	scanf_s("%d", &Bomb);
	playMineSweeper(Bomb, Num);
	// ������ ���ᰡ �Ǹ� ��ŷ�� ����Ѵ�.
	StoreRanking("MineSweeper_Ranking.bin");

}
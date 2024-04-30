#include "MineSweeper.h"
extern void playMineSweeper(int nBomb, int Size);

void main() {

	// 입력받은 지뢰의 개수와 맵의 크기를 저장할 변수 선언
	int Bomb = 0;
	int Num = 0;

	// 랭킹을 불러와 출력을 한다.
	LoadRanking("MineSweeper_Ranking.bin");
	printf(" \t\t<Mine Sweeper>\n");
	PrintRanking();
	// 게임 맵의 크기와 매설할 지뢰의 개수를 사용자로부터 입력을 받는다.
	printf(" 게임 맵 크기를 입력 (100 이하) : ");
	scanf_s("%d", &Num);
	printf(" 매설할 총 지뢰의 개수 입력 : ");
	scanf_s("%d", &Bomb);
	playMineSweeper(Bomb, Num);
	// 게임이 종료가 되면 랭킹을 등록한다.
	StoreRanking("MineSweeper_Ranking.bin");

}
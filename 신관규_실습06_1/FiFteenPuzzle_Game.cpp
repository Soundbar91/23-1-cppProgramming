#include "FifteenPuzzle.h"

int main() {
	
	// FifttenPuzzle.h에 선언된 FifteenPuzzle 클래스를 자료형으로 하는 변수 선언
	FifteenPuzzle Game;

	// 게임의 크기를 입력 받을 변수 선언
	int NUM = 0;

	// 사용자로부터 게임의 크기를 입력 받는다.
	printf("\n\n\t\t1. 3 X 3\t2. 4 X 4\t3. 5 X 5\n\n");
	printf("\t\t게임을 선택해주세요 --> ");
	scanf_s("%d", &NUM);
	NUM += 2;
	system("cls");

	// Game 클래스 publice 함수 Set_Size에 입력받은 게임의 크기를 전달한다.
	Game.Set_Size(NUM);

	// 입력받은 게임의 크기에 따라 랭킹이 구분이 되어야 하기 때문에 해당하는 크기의 랭킹 파일을 전달한다.
	if (NUM == 3) Game.Play("3x3_Ranking.bin");
	else if (NUM == 4) Game.Play("4x4_Ranking.bin");
	else if (NUM == 5) Game.Play("5x5_Ranking.bin");

	return 0;

}
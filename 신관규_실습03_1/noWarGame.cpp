#include "noWarGame.h"

void playRussianRoulette(int nTurns, int nGun, int nBullets) {
	
	// 총알에 맏은 플레이어를 구별하기 위해 배열로 변수 선언
	int People[100] = { 0 };

	// rand 함수를 선언해서 0부터 입력받은 플레이어의 수까지 랜덤으로 난수 발생
	int People_Number = rand() % nTurns;
	printf("\n\n총을 돌렸습니다. %d번부터 시작합니다.\n", People_Number + 1);

	// 반복문을 이용하여 총알이 다 발사될 때까지 게임을 진행
	while ( nBullets != 0) {
		
		// rand함수를 이용하여 0부터 (입력받은 총의 발수 - 1)까지 랜덤으로 난수 발생
		int pos = rand() % nGun;
		
		printf("[%d번]\t탄창을 무작위로 돌렸습니다.\n", People_Number + 1);
		printf("\t엔터를 누르면 격발됩니다...");
		getchar();

		// 단순화를 위해 총알이 입력받은 수부터 내림차순으로 삽탄 됐다고 가정
		// 만약 입력받은 총알의 수와 pos에 저장된 난수가 같으면 아웃
		// nBullets의 변수를 감소 시켜 총알의 개수를 감소
		// 또한, 아웃된 플레이어는 진행되는 게임에서 제외되야 하므로, 해당하는 번호의 배열에 1을 증가
		if (pos == nBullets) {
			printf("\t%d번 참가자가 총에 맞았습니다.\n", People_Number + 1);
			People[People_Number + 1] += 1;
			nBullets -= 1;
		}
		else {
			printf("\t휴~~~ 살았습니다!!!\n");
		}

		People_Number = (People_Number + 1) % nTurns;

		// 다음 플레이어에 해당되는 배열의 수가 1이면 제외를 시켜야 함
		// 반복문을 이용해서 0이 될 때까지 번호를 돌림
		while (People[People_Number + 1] == 1) {
			People_Number = (People_Number + 1) % nTurns;
		}

	}

	printf("\n\n\n");
	for (int i = 1; i < 100; i++) if (People[i] == 1) printf("---->%d번 참가자가 총에 맞았습니다.\n", i);
}
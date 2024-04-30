#include "Ranking.h"
#define NUM_MVP 10

// 랭킹을 저장할 구조체 배열 선언
PlayInfo MVP[NUM_MVP];
int nMVP = NUM_MVP;

// 선언한 구조체 배열을 초기화하는 함수
void initRanking() {

	PlayInfo Noname;
	Noname = { "공석",1000, 1000.0 };
	// 반복문을 이용하여 MVP 구조체 배열에 NoName를 대입 연산을 한다.
	for (int i = 0; i < nMVP; i++) 
		MVP[i]= Noname;

}

// 랭킹을 읽어 출력하는 함수
void LoadRanking(const char* Filename) {

	// 파일을 읽기 모드로 저장한다.
	FILE* fp;
	fopen_s(&fp, Filename, "r");

	// 랭킹 파일이 빈 파일이면 초기화를 시켜준다.
	if (fp == NULL) initRanking();
	// 그렇지 않다면 이진모드의 랭킹 파일을 구조체의 크기로 읽어 온다.
	else {
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);
		fclose(fp);
	}
	
}

// 랭킹을 저장하는 함수
void StoreRanking(const char* Filename) {

	// 파일을 쓰기 모드로 실행한다.
	FILE* fp;
	fopen_s(&fp, Filename, "w");

	// 파일에 아무것도 적혀있지 않다면 함수를 종료한다.
	if (fp == NULL) return;
	// 파일에 구조체의 크기만큼 플레이어의 정보를 이진파일로 저장한다.
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);
	fclose(fp);

}

// 랭킹을 출력하는 함수
void PrintRanking() {
	// 반복문을 이용하여, 이진 파일에서 읽어와 MVP 배열에 저장한 정보 혹은 초기화 한 MVP 배열을 출력한다.
	for (int i = 0; i < nMVP; i++) 
		printf(" [%2d위] %4d %-16s %5.1f\n", i + 1, MVP[i].nMove, 
			MVP[i].name, MVP[i].tElapsed);
}

// 랭킹을 추가하는 함수
int AddRanking(int move,double tElapsed) {

	// 현재 플레이어의 실행 시간과 기존 구조체 배열에 있는 플레이어들의 시간을 비교한다.
	if (tElapsed < MVP[nMVP - 1].tElapsed) {

		int pos = nMVP - 1;

		// 변수 pos의 값을 줄여가며 정보를 비교한다
		// 만약 현재 플레이어의 시간의 값이 기존 보다 크다면 반복문을 탈출
		// MVP 배열 pos 인덱스에 정보를 저장한다
		// 현재 플레이어의 시간의 값이 작다면 배열을 한 칸씩 밀어서 정보를 최신화한다.
		for (; pos > 0; pos--) {
			if (tElapsed >= MVP[pos - 1].tElapsed) break;
			MVP[pos] = MVP[pos - 1];
		}

		MVP[pos].nMove = move;
		MVP[pos].tElapsed = tElapsed;

		// 플레이어의 이름을 입력받아 MVP 구조체에 저장한다.
		printf(" %d위입니다. 이름을 입력하세요 : ", pos + 1);
		scanf_s("%s", &MVP[pos].name, 200);
		return pos + 1;
	}
	return 0;

}
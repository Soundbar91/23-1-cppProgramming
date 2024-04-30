#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

// 플레이어의 정보를 저장할 구조체 선언
struct PlayInfo {
	char name[200];
	int nBomb;
	double tElapsed;
	double Score;
};

// 사용할 함수의 원형을 선언
extern void initRanking();
void LoadRanking(const char* Filename);
void StoreRanking(const char* Filename);
void PrintRanking();
void AddRanking(int nBomb, double tElapsed);

#include <cstdio>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>


// 플레이어의 정보를 저장할 구조체 선언
struct PlayInfo {
	char name[200];
	int nMove;
	double tElapsed;
};

// Ranking.cpp에서 사용할 함수 원형 선언
void LoadRanking(const char* Filename);
void StoreRanking(const char* Filename);
void PrintRanking();
int AddRanking(int move, double tElapsed);
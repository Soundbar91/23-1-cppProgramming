#include <cstdio>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>


// �÷��̾��� ������ ������ ����ü ����
struct PlayInfo {
	char name[200];
	int nMove;
	double tElapsed;
};

// Ranking.cpp���� ����� �Լ� ���� ����
void LoadRanking(const char* Filename);
void StoreRanking(const char* Filename);
void PrintRanking();
int AddRanking(int move, double tElapsed);
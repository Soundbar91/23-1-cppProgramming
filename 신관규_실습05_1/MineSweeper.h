#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

// �÷��̾��� ������ ������ ����ü ����
struct PlayInfo {
	char name[200];
	int nBomb;
	double tElapsed;
	double Score;
};

// ����� �Լ��� ������ ����
extern void initRanking();
void LoadRanking(const char* Filename);
void StoreRanking(const char* Filename);
void PrintRanking();
void AddRanking(int nBomb, double tElapsed);

#include "SpeedGame.h"

// SpeedAddition.cpp������ ��� ������ �������� ����
static int NumGames = 0;
static int NumWins = 0;
static double Score = 0;
static double tElapsed = 0;

// ������ ����ϴ� �Լ�, ���� ������ �����ϱ� ���� bool�� �Լ��� ����
static bool playSpeedAddition(int Num) {

	// pow�� �̿��Ͽ� ����� �ڸ����� �ִ밪�� �ּڰ��� ������ ����
	int Min_Num = pow(10, Num - 1);
	int Max_Num = pow(10, Num) - 1;

	// rand�� �̿��Ͽ� ������ ������ ���ϴ� �ڸ����� �ִ밪�� �ּڰ����� �������Ͽ� ������ �߻�
	// �̸� �����ϴ� ���� 2���� ������� ������ ���� ����
	int X = (rand() % ( Max_Num - Min_Num + 1)) + Min_Num;
	int Y = (rand() % ( Max_Num - Min_Num + 1)) + Min_Num;
	int Result = 0;

	// ������ ���� �� ����, NumGames�� �������� ���� Ƚ���� ī��Ʈ�Ѵ�
	NumGames++;
	printf("[����%2d] : %d + %d = ", NumGames, X, Y);
	scanf_s("%d", &Result);
	// ����, �����̸� NumWins�� �������� ���� ������ ���� ī��Ʈ�Ѵ�
	if (Result == X + Y) NumWins++;
	// ������ �������� 1�� ���� ������, Ʋ������ 0�� ���� ������ �ش�.
	return (Result == X + Y);

}

// ���� �Լ��� ȣ���ϸ鼭 �ð��� ����
void playSpeedAddition(int nPlay, int Num) {

	// �ð� ������ �����ϴ� ��ġ
	clock_t t0 = clock();

	// �ݺ����� �̿��Ͽ� ������ �Լ��� ȣ���Ͽ� ������ Ǭ��.
	for (int i = 0; i < nPlay; i++) if (playSpeedAddition(Num) == false) printf("\tƲ�Ƚ��ϴ�.\n");

	// �ð� ������ �����ϴ� ��ġ
	clock_t t1 = clock();
	// �� ������ ��ȯ
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;

	// ���� Ƚ���� ������ ������ ������ ������ 0, �׷��� ������ ������ ����Ͽ� Score ������ ����
	Score = (NumGames > NumWins) ? 0.0 : 100 * (5.0 * NumGames - tElapsed) / (5.0 * NumGames);
	
	printf("\n���� = %4.1f�� ( �� %4.1f�� )\n", Score, tElapsed);
}
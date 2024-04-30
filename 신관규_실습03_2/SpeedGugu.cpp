#include "SpeedGame.h"

// SpeedGugu.cpp������ ��� ������ �������� ����
static int NumGames = 0;
static int NumWins = 0;
static double Score = 0;
static double tElapsed = 0;

// �������� ����ϴ� �Լ�, ���� ������ �����ϱ� ���� bool�� �Լ��� ����
static bool playGuguOnce() {

	// rand�� �̿��Ͽ� ������ ������ 2 ~ 9�� �������Ͽ� ������ �߻�
	// �̸� �����ϴ� ���� 2���� ������� ������ ���� ����
	int Dan = rand() % 8 + 2;
	int Weight = rand() % 8 + 2;
	int Result = 0;

	// ������ ���� �� ����, NumGames�� �������� ���� Ƚ���� ī��Ʈ�Ѵ�
	NumGames++;
	printf("[����%2d] : %2d x %2d = ", NumGames, Dan, Weight);
	scanf_s("%d", &Result);
	// ����, �����̸� NumWins�� �������� ���� ������ ���� ī��Ʈ�Ѵ�
	if (Result == Dan * Weight) NumWins++;
	// ������ �������� 1�� ���� ������, Ʋ������ 0�� ���� ������ �ش�.
	return (Result == Dan * Weight);

}

// ������ �Լ��� ȣ���ϸ鼭 �ð��� ����
void playSpeedGugu(int nPlay) {
	
	// �ð� ������ �����ϴ� ��ġ
	clock_t t0 = clock();
	
	// �ݺ����� �̿��Ͽ� ������ �Լ��� ȣ���Ͽ� ������ Ǭ��.
	for (int i = 0; i < nPlay; i++) {
		if (playGuguOnce() == false) printf("\tƲ�Ƚ��ϴ�.\n");
	}

	// �ð� ������ �����ϴ� ��ġ
	clock_t t1 = clock();
	// �� ������ ��ȯ
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;
	
	// ���� Ƚ���� ������ ������ ������ ������ 0, �׷��� ������ ������ ����Ͽ� Score ������ ����
	Score = (NumGames > NumWins) ? 0.0 : 100 * (5.0 * NumGames - tElapsed) / (5.0 * NumGames);

	printf("\n���� = %4.1f�� ( �� %4.1f�� )\n", Score, tElapsed);
}
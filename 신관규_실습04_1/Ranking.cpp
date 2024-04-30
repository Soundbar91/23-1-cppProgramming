#include "Ranking.h"
#define NUM_MVP 10

// ��ŷ�� ������ ����ü �迭 ����
PlayInfo MVP[NUM_MVP];
int nMVP = NUM_MVP;

// ������ ����ü �迭�� �ʱ�ȭ�ϴ� �Լ�
void initRanking() {

	PlayInfo Noname;
	Noname = { "����",1000, 1000.0 };
	// �ݺ����� �̿��Ͽ� MVP ����ü �迭�� NoName�� ���� ������ �Ѵ�.
	for (int i = 0; i < nMVP; i++) 
		MVP[i]= Noname;

}

// ��ŷ�� �о� ����ϴ� �Լ�
void LoadRanking(const char* Filename) {

	// ������ �б� ���� �����Ѵ�.
	FILE* fp;
	fopen_s(&fp, Filename, "r");

	// ��ŷ ������ �� �����̸� �ʱ�ȭ�� �����ش�.
	if (fp == NULL) initRanking();
	// �׷��� �ʴٸ� ��������� ��ŷ ������ ����ü�� ũ��� �о� �´�.
	else {
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);
		fclose(fp);
	}
	
}

// ��ŷ�� �����ϴ� �Լ�
void StoreRanking(const char* Filename) {

	// ������ ���� ���� �����Ѵ�.
	FILE* fp;
	fopen_s(&fp, Filename, "w");

	// ���Ͽ� �ƹ��͵� �������� �ʴٸ� �Լ��� �����Ѵ�.
	if (fp == NULL) return;
	// ���Ͽ� ����ü�� ũ�⸸ŭ �÷��̾��� ������ �������Ϸ� �����Ѵ�.
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);
	fclose(fp);

}

// ��ŷ�� ����ϴ� �Լ�
void PrintRanking() {
	// �ݺ����� �̿��Ͽ�, ���� ���Ͽ��� �о�� MVP �迭�� ������ ���� Ȥ�� �ʱ�ȭ �� MVP �迭�� ����Ѵ�.
	for (int i = 0; i < nMVP; i++) 
		printf(" [%2d��] %4d %-16s %5.1f\n", i + 1, MVP[i].nMove, 
			MVP[i].name, MVP[i].tElapsed);
}

// ��ŷ�� �߰��ϴ� �Լ�
int AddRanking(int move,double tElapsed) {

	// ���� �÷��̾��� ���� �ð��� ���� ����ü �迭�� �ִ� �÷��̾���� �ð��� ���Ѵ�.
	if (tElapsed < MVP[nMVP - 1].tElapsed) {

		int pos = nMVP - 1;

		// ���� pos�� ���� �ٿ����� ������ ���Ѵ�
		// ���� ���� �÷��̾��� �ð��� ���� ���� ���� ũ�ٸ� �ݺ����� Ż��
		// MVP �迭 pos �ε����� ������ �����Ѵ�
		// ���� �÷��̾��� �ð��� ���� �۴ٸ� �迭�� �� ĭ�� �о ������ �ֽ�ȭ�Ѵ�.
		for (; pos > 0; pos--) {
			if (tElapsed >= MVP[pos - 1].tElapsed) break;
			MVP[pos] = MVP[pos - 1];
		}

		MVP[pos].nMove = move;
		MVP[pos].tElapsed = tElapsed;

		// �÷��̾��� �̸��� �Է¹޾� MVP ����ü�� �����Ѵ�.
		printf(" %d���Դϴ�. �̸��� �Է��ϼ��� : ", pos + 1);
		scanf_s("%s", &MVP[pos].name, 200);
		return pos + 1;
	}
	return 0;

}
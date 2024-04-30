#include "Ranking.h"

// ����Ű�� ���� ���������� �����Ѵ�.
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

// ���������� ������ ����Ű�� ���� ������ �迭�� ����
static int DirKey[4] = { Left, Right, Up, Down };
// ���� ������ ���ڵ��� ���� �� 2���� �迭 ����
static int Map[6][6];
// ���� ��ǥ�� ������ ������ ���� ����
static int X, Y;
// ������ Ƚ���� ������ ���� ����
static int nMove;
// ������ ���۵Ǵ� �ð�
static clock_t tStart;
// ���÷��̸� ���� ������ 3���� �迭
static int Re_Map[300][6][6];
// �߰��� ������ ������ �����ϱ� ���� ���� ����
static int Save_input = 0;
// ������ ũ�⸦ �����ϱ� ���� ���� ����
int NUM = 0;

// �迭�� �ʱ�ȭ �ϴ� �Լ�
static void init() {

	// �ݺ����� �̿��ؼ� ��� ���� ������ ���ڸ��� ������.
	for (int i = 0; i < NUM * NUM - 1; i++) Map[i / NUM][i % NUM] = i + 1;
	Map[NUM - 1][NUM - 1] = 0;
	X = NUM - 1; Y = NUM - 1;

	// ���� �ð��� �̵� Ƚ���� �ʱ�ȭ�Ѵ�.
	srand(time(NULL));
	tStart = clock();
	nMove = 0;

}

// ���� ��� �Լ�
static void Display() {

	system("cls");
	printf("\tFifteen Puzzle\n\t");
	printf("--------------\n\t");
	// �ݺ����� �̿��ؼ� �迭�� ����� ���� ���ڵ��� ����Ѵ�.
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
			if (Map[i][j] > 0) printf("%3d", Map[i][j]);
			else printf("");
		}
		printf("\n\t");
	}
	printf("--------------\n\t");

	// �ǽð����� �ҿ� �ð��� �̵� Ƚ���� ���
	clock_t t1 = clock();
	double Time = (double)(t1 - tStart) / CLOCKS_PER_SEC;

	printf("\n\t�̵� Ƚ�� : %6d\n\t�ҿ� �ð� : %6.1f\n\n", nMove, Time);
}

// ���� ������ �߰��� �����ϴ� �Լ�
void Save_Map(int nMove, double Time) {

	// �������Ϸ� ������� ���� ����
	FILE* fp;
	fopen_s(&fp, "SaveFile.bin", "w");
	fwrite(&Map, sizeof(Map), 1, fp);
	fclose(fp);

	// �������Ϸ� ���� �������� ũ�⸦ �����Ѵ�
	FILE* fp_1;
	fopen_s(&fp_1, "Save_Map_Num.bin", "w");
	fwrite(&NUM, sizeof(int), 1, fp_1);
	fclose(fp_1);

	// �������Ϸ� �̵� Ƚ���� �����Ѵ�.
	FILE* fp_2;
	fopen_s(&fp_2, "Save_Move.bin", "w");
	fwrite(&nMove, sizeof(int), 1, fp_2);
	fclose(fp_2);

	// �������Ϸ� �ҿ� �ð��� �����Ѵ�.
	FILE* fp_3;
	fopen_s(&fp_3, "Save_TIme.bin", "w");
	fwrite(&Time, sizeof(double), 1, fp_3);
	fclose(fp_3);

}

// ����Ű�� �Է¹޾� ������ �����̴� �Լ�
static bool Move(int Dir) {

	// �� ����Ű���� �Է��� �޾��� ��, ��� ������ �˻��Ͽ� �̵��� �� �ִ��� �������� Ȯ���Ѵ�.
	if (Dir == Right && X > 0) {
		// �� ���� ������ �˻��Ͽ�, �̵��� �����ϴٸ� ���� �ű��.
		Map[Y][X] = Map[Y][X - 1];
		Map[Y][--X] = 0;
	}
	else if (Dir == Left && X < NUM - 1) {
		// �� ������ ������ �˻��Ͽ�, �̵��� �����ϴٸ� ���� �ű��.
		Map[Y][X] = Map[Y][X + 1];
		Map[Y][++X] = 0;
	}
	else if (Dir == Up && Y < NUM - 1) {
		// �� �Ʒ� ������ �˻��Ͽ�, �̵��� �����ϴٸ� ���� �ű��.
		Map[Y][X] = Map[Y + 1][X];
		Map[++Y][X] = 0;
	}
	else if (Dir == Down && Y > 0) {
		// �� �� ������ �˻��Ͽ�, �̵��� �����ϴٸ� ���� �ű��.
		Map[Y][X] = Map[Y - 1][X];
		Map[--Y][X] = 0;
	}
	// q�� ���� ������ �� �� �ְ���.
	else if (Dir == 113) {
		Save_input += 1;
		return true;
	}
	// �̵��� �����ߴٸ�, false�� ��ȯ�Ѵ�.
	else return false;

	// �̵��� ���������� �ƴٸ�, �̵� Ƚ���� �ø��� true�� ��ȯ�Ѵ�.
	nMove++;
	return true;
}

// ���÷��̸� �����ϴ� �Լ�
void Recoard() {

	// 3�������� ����� �迭�� 2���� ���� ���� ���� �����Ѵ�.
	// �̵��� �ƴٸ�, nMove�� ���� �����ϰ�, �̿� ���� 3���� �迭�� 2���� ���� ���� ���� �����Ѵ�.
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
				Re_Map[nMove][i][j] = Map[i][j];
		}
	}

}

// ���÷��̸� �����ִ� �Լ�
void RePlay() {

	// �ݺ����� �̿��Ͽ� 3���� �迭�� ����Ѵ�.
	for (int i = 0; i < nMove; i++) {
		system("cls");
		printf("\tFifteen Puzzle\n\t");
		printf("--------------\n\t");
		for (int j = 0; j < NUM; j++) {
			for (int k = 0; k < NUM; k++) {
				if (Re_Map[i][j][k] > 0) printf("%3d", Re_Map[i][j][k]);
				else printf("");
			}
			printf("\n\t");
		}
		printf("--------------\n\t");
	}
	printf("���͸� �����ּ���..");
	_getche();

}

// ���ڸ� ���� �Լ�
static void Shuffle(int nShuffle) {

	// Move �Լ��� ������ �̿��Ͽ� ������ �����δ�.
	for (int i = 0; i < nShuffle; i++) {
		int Key = DirKey[rand() % 4];
		// ���� Move�Լ��� �̿��ؼ� ������ �� ���ٸ�, ������ i�� ���ҽ�Ű�� �ٽ� �ݺ����� ������.
		if (Move(Key) == false) { i--; continue; }
		Display();
		Sleep(50);
	}

}

// ������ �� ���������� Ȯ���ϴ� �Լ�
static bool isDone() {

	// �ݺ����� �̿��Ͽ� ������ ��Ȯ�� ��ġ�� ������ Ȯ��
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
			if (Map[i][j] != i * NUM + j + 1)
				return (i == NUM - 1) && (j == NUM - 1);
		}
	}
	return true;
}

// ���� Ű�� �޾Ƶ帮�� �Լ�
static int getDirKey() {
	// ����Ű Ȥ�� 'q'�� �Է¹޾ҾҴٸ� _getche()�� ���ڸ� �Է� �ް� �׷��� �ʴٸ� 0�� Move�Լ��� ���ϰ����� �ش�.
	return ( _getche() == 224 || _getche() == 113 ) ? _getche() : 0;
}

// ��������� �����ϴ� �Լ�
int PlayFifteenPuzzle(int Num) {

	// �Լ��κ��� ���޹��� �Ű������� NUM�� �����Ͽ� ������ ũ�⸦ ���Ѵ�.
	NUM = Num;
	// ���÷��� ���θ� ������ ���� ����
	int RePlay_input = 0;

	// ���� ������ �� �Լ�
	init();
	Display();
	PrintRanking();
	printf("\n ������ �����ּ��� (����)...");
	_getche();
	Shuffle(100);
	printf("\n ������ ���۵˴ϴ�...");

	nMove = 0;
	tStart = clock();

	// isDoan �Լ��� �̿��Ͽ� �迭�� ���������� ��ġ�� �ƴ��� Ȯ���Ͽ� �ݺ����� ������.
	while (!isDone()) {
		Move(getDirKey());
		Recoard();
		Display();
		if (Save_input == 1) break;
	}
	clock_t t1 = clock();

	// �߰��� 'q'�� ���� ������ �Ͽ��ٸ�, Save_Map�Լ��� �̿��Ͽ� ��� ������ �����Ѵ�.
	if (Save_input == 1) {
		double Save_time = (double)(t1 - tStart) / CLOCKS_PER_SEC;
		Save_Map(nMove, Save_time);
		system("cls");
		printf("\n\n\t\t������ ����Ǿ����ϴ�.\n\n");
		printf("\n\n\t\t������ �����մϴ�.\n\n");
		return 0; // ��ȯ ���� 0�� �� �����Լ��� �ۼ��� ���ǹ��� �̿��Ͽ� ������ �����Ų��.
	}

	// ���÷��̸� ���
	printf(" ���÷��̸� ���ðڽ��ϱ� (1. YES 2. NO) --> ");
	scanf_s("%d", &RePlay_input);
	if (RePlay_input == 1) RePlay();

	// ��ȯ ������ ������ Ƚ���� �ð��� ��ȯ
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	return AddRanking(nMove, d);
}
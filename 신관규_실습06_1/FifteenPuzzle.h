#include "Ranking.h" // ��ŷ �ý����� ����ϱ� ���� �ش� ��� ������ ����
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
// ����Ű�� ���� ���������� �����Ѵ�.
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
// ���������� ������ ����Ű�� ���� ������ �迭�� ����
static int DirKey[4] = { Left, Right, Up, Down };

// ��������� ���� class ����
class FifteenPuzzle {

private:
	// ������ӿ��� ����� �������� private ��� ������ ����
	int Map[6][6];
	int Re_Map[300][6][6];
	int X, Y;
	int nMove;
	int Game_Size;
	int Save_input = 0;
	clock_t tStart;
	// Ranking.h�� ����� RankingBoard Ŭ������ �ڷ������� �ϴ� ��ü ����
	RankingBoard Ranking;

	// ���� ���� �ʱ�ȭ �ϴ� �Լ��� private ��� �Լ��� ����
	void init() {

		// �ݺ����� �̿��ؼ� ��� ���� ������ ���ڸ��� ������.
		for (int i = 0; i < Game_Size * Game_Size - 1; i++) Map[i / Game_Size][i % Game_Size] = i + 1;
		Map[Game_Size - 1][Game_Size - 1] = 0;
		X = Game_Size - 1; Y = Game_Size - 1;

		// ���� �ð��� �̵� Ƚ���� �ʱ�ȭ�Ѵ�.
		srand(time(NULL));
		tStart = clock();
		nMove = 0;

	}

	// ���� ��� �Լ��� private ��� �Լ��� ����
	void Display() {

		system("cls");
		printf("\tFifteen Puzzle\n\t");
		printf("--------------\n\t");
		// �ݺ����� �̿��ؼ� �迭�� ����� ���� ���ڵ��� ����Ѵ�.
		for (int i = 0; i < Game_Size; i++) {
			for (int j = 0; j < Game_Size; j++) {
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

	// ����Ű�� �Է¹޾� ������ �����̴� �Լ��� private ��� �Լ��� ����
	bool Move(int Dir) {
		// �� ����Ű���� �Է��� �޾��� ��, ��� ������ �˻��Ͽ� �̵��� �� �ִ��� �������� Ȯ���Ѵ�.
		if (Dir == Right && X > 0) {
			// �� ���� ������ �˻��Ͽ�, �̵��� �����ϴٸ� ���� �ű��.
			Map[Y][X] = Map[Y][X - 1];
			Map[Y][--X] = 0;
		}
		else if (Dir == Left && X < Game_Size - 1) {
			// �� ������ ������ �˻��Ͽ�, �̵��� �����ϴٸ� ���� �ű��.
			Map[Y][X] = Map[Y][X + 1];
			Map[Y][++X] = 0;
		}
		else if (Dir == Up && Y < Game_Size - 1) {
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

	// ���ڸ� ���� �Լ��� private ��� �Լ��� ����
	void Shuffle(int nShuffle) {

		// Move �Լ��� ������ �̿��Ͽ� ������ �����δ�.
		for (int i = 0; i < nShuffle; i++) {
			int Key = DirKey[rand() % 4];
			// ���� Move�Լ��� �̿��ؼ� ������ �� ���ٸ�, ������ i�� ���ҽ�Ű�� �ٽ� �ݺ����� ������.
			if (Move(Key) == false) { i--; continue; }
			Display();
			Sleep(50);
		}

	}

	// ������ �� ���������� Ȯ���ϴ� �Լ��� private ��� �Լ��� ����
	bool isDone() {

		// �ݺ����� �̿��Ͽ� ������ ��Ȯ�� ��ġ�� ������ Ȯ��
		for (int i = 0; i < Game_Size; i++) {
			for (int j = 0; j < Game_Size; j++) {
				if (Map[i][j] != i * Game_Size + j + 1)
					return (i == Game_Size - 1) && (j == Game_Size - 1);
			}
		}
		return true;

	}

	// ���� ������ �߰��� �����ϴ� �Լ��� private ��� �Լ��� ����
	void Save_Map(int nMove, double Time) {

		// �������Ϸ� ������� ���� ����
		FILE* fp;
		fopen_s(&fp, "SaveFile.bin", "w");
		fwrite(&Map, sizeof(Map), 1, fp);
		fclose(fp);

		// �������Ϸ� ���� �������� ũ�⸦ �����Ѵ�
		FILE* fp_1;
		fopen_s(&fp_1, "Save_Map_Game_Size.bin", "w");
		fwrite(&Game_Size, sizeof(int), 1, fp_1);
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

	// ���÷��̸� �����ϴ� �Լ��� private ��� �Լ��� ����
	void Recoard() {

		// 3�������� ����� �迭�� 2���� ���� ���� ���� �����Ѵ�.
		// �̵��� �ƴٸ�, nMove�� ���� �����ϰ�, �̿� ���� 3���� �迭�� 2���� ���� ���� ���� �����Ѵ�.
		for (int i = 0; i < Game_Size; i++) {
			for (int j = 0; j < Game_Size; j++) {
				Re_Map[nMove][i][j] = Map[i][j];
			}
		}

	}

	// ���÷��̸� �����ִ� �Լ��� private ��� �Լ��� ����
	void RePlay() {

		// �ݺ����� �̿��Ͽ� 3���� �迭�� ����Ѵ�.
		for (int i = 0; i < nMove; i++) {
			system("cls");
			printf("\tFifteen Puzzle\n\t");
			printf("--------------\n\t");
			for (int j = 0; j < Game_Size; j++) {
				for (int k = 0; k < Game_Size; k++) {
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

	// ���� Ű�� �޾Ƶ帮�� �Լ��� private ��� �Լ��� ����
	int getDirKey() {
		// ����Ű Ȥ�� 'q'�� �Է¹޾ҾҴٸ� _getche()�� ���ڸ� �Է� �ް� �׷��� �ʴٸ� 0�� Move�Լ��� ���ϰ����� �ش�.
		return (_getche() == 224 || _getche() == 113) ? _getche() : 0;
	}

public:

	// �Ѱܹ��� ������ ũ�⸦ ���� Private ���� Game_Size�� ���� �ٲ۴�.
	void Set_Size(int Size) { Game_Size = Size; };

	// ������ �����ϴ� �Լ��� public ��� �Լ��� ����
	// �Ѱܹ��� ��ŷ ������ ��ŷ�� �ҷ����� �����ϸ� ������ �����Ѵ�.
	void Play(const char* Filename) {

		// ���÷��� ���θ� ������ ���� ����
		int RePlay_input = 0;

		// ���� ������ �� �Լ�
		// Ranking.h�� �ִ� publice �Լ��� �Ѱܹ��� ��ŷ ������ �̿��Ͽ� ��ŷ�� �ҷ����� ����Ѵ�.
		Ranking.Load(Filename);
		init();
		Display();
		Ranking.Print();
		
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
			return; // �����Լ��� �ۼ��� ���ǹ��� �̿��Ͽ� ������ �����Ų��.
		}

		// ���÷��̸� ���
		printf(" ���÷��̸� ���ðڽ��ϱ� (1. YES 2. NO) --> ");
		scanf_s("%d", &RePlay_input);
		if (RePlay_input == 1) RePlay();

		// ��ȯ ������ ������ Ƚ���� �ð��� ��ȯ
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;

		// Ranking.h�� �ִ� publice �Լ��� ������ Ƚ���� �ҿ�ð� �׸��� ���� �̸��� �Ѱ� ��ŷ�� �����Ѵ�.
		Ranking.Add(nMove, d);
		Ranking.Store(Filename);
	}
};
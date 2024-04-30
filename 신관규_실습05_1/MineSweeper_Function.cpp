#include "MineSweeper.h"

// ���� �ʿ��� ���ڰ� �ִ��� �������� ����� ǥ���ϰ��� ���������� ����
enum LabelType { Empty = 0, Bomb = 9 };
// ����ũ ���� ��ǥ ���¸� ����� ǥ���ϰ��� ���������� ����
enum MaskType { Hide = 0, Open  = 1, Flag = 2 };

// ���ڰ� ��ġ�Ǵ� �ʰ� ���ڰ� ������ ����ũ ���� ����
static int MineMapMask[101][101];
static int MineMapLabel[101][101];
// ���� ũ��� ��ü ������ ���� �����ϴ� ���� ����
static int nX, nY = 0;
static int nBomb = 0;

// inline �Լ��� �����Ͽ� ��ũ�� ����� �ϴ� �Լ�
// ����ũ �ʰ� ���� ���� �����ڸ� �̿��� ���ϰ� �ʿ� ������ �� �ִ�.
inline int& Mask(int X, int Y) { return MineMapMask[Y][X]; }
inline int& Label(int X, int Y) { return MineMapLabel[Y][X]; }
// ��ǥ�� ���� ���� �ִ���, ��ǥ�� ���ڰ� �ִ��� �������� �˻��ϴ� ��ũ�� �Լ��� ����
inline bool isValid(int X, int Y) { return (X >= 0 && X < nX&& Y >= 0 && Y < nY); }
inline bool isBomb(int X, int Y) { return isValid(X, Y) && Label(X, Y) == Bomb; }
inline bool isEmpty(int X, int Y) { return isValid(X, Y) && Label(X, Y) == Empty; }

// �Է¹��� ��ǥ�� �˻��ϴ� �Լ�
static void Dig(int X, int Y) {

	// ��ǥ�� ���� ���� �ִ���, �׸��� �Է¹��� ��ǥ�� ����ũ �ʿ��� ���� �ִ��� �ʴ���(���� 1�� �ƴ���) Ȯ���Ѵ�.
	if (isValid(X, Y) && Mask(X, Y) != Open) {
		// ����ũ ���� �Է� ���� ��ǥ ��ġ�� Open����(���� 1��) �ٲ۴�.
		Mask(X, Y) = Open;
		// ���࿡ �Է¹��� ��ǥ�� ���� �ʿ����� ���� 0�̸�, ������ �ִ� 8ĭ�� ��ǥ���� ��� �Լ��� �˻��Ѵ�.
		if (Label(X, Y) == 0) {
			Dig(X - 1, Y - 1);
			Dig(X - 1, Y);
			Dig(X - 1, Y + 1);
			Dig(X, Y - 1);
			Dig(X, Y);
			Dig(X, Y + 1);
			Dig(X + 1, Y - 1);
			Dig(X + 1, Y);
			Dig(X + 1, Y + 1);
		}
	}

}

// ����� ��ġ�ϴ� �Լ�
static void Mark(int X, int Y) {
	// ��ǥ�� �������� �ְ�, ����ũ �ʿ��� �ش� ��ǥ�� ������ ���� ���� ����(���� 0)��� �ش� ��ǥ�� ���� Flag(2)�� �ٲ۴�.
	if (isValid(X, Y) && Mask(X, Y) == Hide) Mask(X, Y) = Flag;
}

// ����� ������ ���� �Լ�
static int getBombCount() {

	// ����� ������ ���� ������ ���� ����
	int Count = 0;

	// �ݺ����� �̿��Ͽ� ����ũ�� �� ���¸� �˻��Ͽ� ����� �ִ� ����(���� 2)��� ������ ������Ų��.
	for (int Y = 0; Y < nY; Y++) {
		for (int X = 0; X < nX; X++) {
			if (Mask(X, Y) == Flag) Count++;
		}
	}

	// ��ȯ������ ����� ������ ��ȯ�Ѵ�.
	return Count;
}

// ���� ���� ���� ����ϴ� �Լ�
static void Print() {

	system("cls");
	printf(" �߰� : %2d ��ü : %2d\n", getBombCount(), nBomb);
	printf("  ");
	// �ݺ����� �̿��Ͽ� ���� ���ڸ� ����Ѵ�.
	for (int i = 0; i < nX; i++) printf(" %2d", i);
	printf("\n");
	// �ݺ����� �̿��Ͽ� ���� ���ڸ� ����Ѵ�.
	for (int Y = 0; Y < nY; Y++) {
		printf("%2d ", Y);
		// �ݺ����� �̿��Ͽ� ����ũ ���� ����Ѵ�.
		// �̶� inline�Լ��� �̿��Ͽ� ����ũ �� ��ǥ�� ����(��)�� ���� ����� �޸��Ѵ�.
		for (int X = 0; X < nX; X++) {
			if (Mask(X, Y) == Hide) printf(" ��");
			else if (Mask(X, Y) == Flag) printf(" ��");
			else {
				// ��ǥ�� �˻����� �� ��ź�� �ִٸ� ���ǹ��� ���� �Ǳ� ������ �����ϰ� �ȴ�.
				// �� �̿ܿ� ��Ȳ������ ���� ���� ����Ѵ�.
				// ���ü��� ���� ���� �ʿ��� ���ڰ� ���� ĭ�� @�� ����Ͽ���.
				if (isBomb(X, Y)) printf(" ��");
				else if (isEmpty(X, Y)) printf("  @");
				else printf(" %2d", Label(X, Y));
			}
		}
		printf("\n");
	}

}

// �Է¹��� ��ǥ�� ���� 8ĭ�� �ִ� ������ ���� ���� �Լ�
static int CountNberBombs(int X, int Y) {
	
	// ������ ���� ���� ������ ���� ����
	int Count = 0;

	// �ݺ����� �̿��Ͽ� �Է¹��� ��ǥ�� 8ĭ�� �˻��Ѵ�.
	for (int YY = Y - 1; YY <= Y + 1; YY++) {
		for (int XX = X - 1; XX <= X + 1; XX++) {
			// ���� �����ȿ� �����ϰ�, ���ڸʿ��� �ش� ��ǥ�� ��ź�� �ִٸ�(���� 9) ������ ������Ų��.
			if (isValid(XX, YY) && Label(XX, YY) == Bomb)
				Count++;
		}
	}

	// ��ȯ ������ ������ ���� ��ȯ
	return Count;
}

// ���� �ʱ�ȭ �ϴ� �Լ�
static void init(int Total, int Size) {
	
	// �Է� ���� ���� ũ�⸦ ���� ������ �����Ѵ�.
	nX = Size; nY = Size;

	srand((unsigned int)time(NULL));

	// �ݺ����� �̿��ؼ� ����ũ �ʿ��� �ƹ��͵� �ǵ��� �ʾҴٴ� �����(���� 0), ���� �ʿ��� 0�� �����Ѵ�.
	for (int Y = 0; Y < nY; Y++) {
		for (int X = 0; X < nX; X++) {
			Mask(X, Y) = Hide;
			Label(X, Y) = 0;
		}
	}

	// �Է¹��� ��ź�� ������ ���� ������ �����Ѵ�.
	nBomb = Total;

	// �ݺ����� ������ �̿��Ͽ� ���� �ʿ� ���ڸ� �������� �����Ѵ�.
	for (int i = 0; i < nBomb; i++) {

		int X, Y = 0;

		// ������ �߻��� ��ǥ�� ���� �ʿ��� ���ڰ� ���� ������ �ݺ����� ������.
		do {
			X = rand() % nX;
			Y = rand() % nY;
		} while (Label(X, Y) != Empty);

		// �ش� ��ǥ�� ���ڸʿ� ��ź�� ��ġ(���� 9)�Ѵ�.
		Label(X, Y) = Bomb;
	}

	// �ݺ����� �̿��Ͽ� ���� �ʿ��� ���ڰ� ���� ��ǥ���� ���� 8ĭ�� ���¸� �����ؼ� ������ ������ ���´�.
	for (int Y = 0; Y < nY; Y++) {
		for (int X = 0; X < nX; X++) {
			if (Label(X, Y) == Empty) Label(X, Y) = CountNberBombs(X, Y);
		}
	}

}

// ��ǥ�� �Է¹޴� �Լ�
static bool getPos(int& X, int& Y) {

	bool isBomb = false;
	int Flag = 0;

	// ����ڷκ��� ����� ��ġ�� ������ �Է��� �޴´�.
	printf("����� ��ġ�Ͻðڽ��ϱ� (1. YES 2. NO) --> ");
	scanf_s("%d", &Flag);

	// ���ǹ����� ��츦 ������ ��� ���� �Է��� �޴´�.
	if (Flag == 1) {
		isBomb = true;
		int X_ = 0, Y_ = 0;
		printf("�� �Է� --> "); 
		scanf_s("%d", &X_);
		printf("�� �Է� --> ");
		scanf_s("%d", &Y_);

		X = X_; Y = Y_;
		return isBomb;
	}
	else {
		int X_ = 0, Y_ = 0;
		printf("�� �Է� --> ");
		scanf_s("%d", &X_);
		printf("�� �Է� --> "); 
		scanf_s("%d", &Y_);

		X = X_; Y = Y_;
		return isBomb;
	}
}

// ������ ���� ������ �˻��ϴ� �Լ�
static int CheckDone() {
	
	int Count = 0;
	// �ݺ����� �̿��Ͽ� ����ũ ���� �˻��Ѵ�.
	for (int Y = 0; Y < nY; Y++) {
		for (int X = 0; X < nX; X++) {
			// ����ũ �ʿ� ������ �ʴ� ĭ(���� 1�� �ƴ�)�� �ִٸ� ������ ������Ų��.
			if (Mask(X, Y) != Open) Count++;
			// ���� ���ڰ� ��ĭ�̶� ���� ������ -1�� ��ȯ�Ѵ�.
			else if (isBomb(X, Y)) return -1;
		}
	}
	// ������Ų ������ ���� ��ź�� ������ ���ٸ� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
	return (Count == nBomb) ? 1 : 0;
}

// ���� ã�� ������ �� �Լ�
void playMineSweeper(int Total, int Size) {

	int X, Y, status = 0;
	// ���� ���� �ʱ�ȭ �� ��ŷ�� �ҷ��´�.
	init(Total, Size);
	LoadRanking("MineSweeper_Ranking.bin");
	
	// ���� �ð�
	clock_t t1 = clock();

	// �ݺ����� �̿��Ͽ� ���� ������ �����ϸ� ������ ����ȴ�.
	do {
		Print();
		// bool ������ �����Ͽ� getPost���� ��ȯ�ϴ� ��, ������ �����Ѵ�.
		// ����� ��ġ�ϰ� �Ǹ� ��ȯ���� ���̹Ƿ� Mark �Լ��� �Ѿ��.
		// ��ġ�� ���� ������ Dig �Լ��� �Ѿ��.
		bool isBomb = getPos(X, Y);

		if (isBomb) Mark(X, Y);
		else Dig(X, Y);
		
		// �ݺ��� �������� ���� ���������� �˻��Ѵ�.
		status = CheckDone();
	} while (status== 0);

	// ���� �ð�
	clock_t t2 = clock();
	double Clear_time = (double)(t2 - t1) / CLOCKS_PER_SEC;

	// ������ ���ᰡ �Ǹ� ������ ���и� �����Ͽ� ����Ѵ�.
	Print();
	if (status < 0) printf("\n���� : ���� ���� !!!\n\n");

	// ������ �ϸ� �ҿ� �ð��� ����ϰ� ��ŷ�� �����Ѵ�.
	else {
		printf("\n ���� : Ž�� ���� !!!\n");
		printf(" �ҿ� �ð� : %6.1f\n", Clear_time);
		AddRanking(nBomb, Clear_time);
	}

}
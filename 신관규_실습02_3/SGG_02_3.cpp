#include <stdio.h>
#include <conio.h>

void main() {

	// Guessing Numbers
	int Num = 0, Min = 1, Max = 999, Guess = 0, Score = 100;

	// ���� 3�ڸ� �Է¹޴´�.
	printf("�� �ڸ� �� �Է�(1 ~ 999) : ");

	// �Է� ���� �� �ڸ� ���ڸ� ���� ���·� �Է¹޾� �����Ѵ�.
	char Hundred = _getch();
	printf(">");
	char Ten = _getch();
	printf("_");
	char One = _getch();
	printf("<\n\n");

	// �ƽ�Ű �ڵ带 �̿��Ͽ� ���� ���·� �Է¹��� ���� ���ڷ� �����Ѵ�.
	Num = (Hundred - '0') * 100 + (Ten - '0') * 10 + (One - '0');

	printf("���� �� -2��, ��ȸ�� �� 50��\n\n");

	// �ݺ����� �̿��ؼ� ���ڸ� �Է¹޴´�.
	for (int i = 1; i <= 50; i++) {

		printf("���� ���� : %3d\n", Score);
		printf("[%2d]ȸ %3d ~ %3d ������ �� ���� => ", i-1, Min, Max);
		
		char Hundred = _getch();
		printf(")");
		char Ten = _getch();
		printf("_");
		char One = _getch();
		printf("(");

		Guess = (Hundred - '0') * 100 + (Ten - '0') * 10 + (One - '0');

		// ���� ���ڸ� ���߸� �ݺ����� Ż���Ѵ�.
		if (Num == Guess) break;

		// ���亸�� ���� ���ڸ� �Է��ϸ� �� ���ڸ� ���� Min�� �����Ͽ� ������ ������.
		else if (Num > Guess) {
			printf(" �� ū �����Դϴ� ! \n");
			Min = Guess;
			Score -= 2;
		}

		// ���亸�� ū ���ڸ� �Է��ϸ� �� ���ڸ� ���� Max�� �����Ͽ� ������ ������.
		else {
			printf(" �� ���� �����Դϴ� ! \n");
			Max = Guess;
			Score -= 2;
		}

	}

	// ���� ����� ������ ����Ѵ�.
	printf("\n\n\n %s !!! ������ %d\n", (Num == Guess) ? "����" : "����", Num);
	printf(" ���� ���� = %d\n", Score);
}
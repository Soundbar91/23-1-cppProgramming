#include "SpeedGame.h"

void main() {

	// ���� �����⿡ ���� ���� �õ� ���� ����
	srand((unsigned)time(NULL));

	// ������ �� 10�� ����ڷκ��� �Է� ���� ���ڸ� ������ ���� ����
	int nPlay = 10;
	int Num = 0;

	// ����ڷκ��� ���ڸ� �Է� �޾�, � ������ �� ������ ����
	printf(" ������ �����Ͻÿ�.\n");
	printf(" 1 : ������, 2 : �� �ڸ��� ����, 3 ~ 9 : 3 ~ 9 �ڸ� �� ���� == > ");
	scanf_s("%d", &Num);
	getchar();
	system("cls");
	
	if (Num == 1) printf("[���ǵ� ������ ����]\n\n");
	else if (Num == 2) printf("[���ǵ� �� �ڸ��� ���� ����]\n\n");
	else printf("[���ǵ� %d�ڸ� ���� ����]\n\n", Num);
	
	printf(" %d�� �׽�Ʈ �ϰڽ��ϴ�.\n", nPlay);
	printf(" ũ�� �ɼ����� �Ͻð�...\n �غ�Ǹ� ���͸� ��������...");
	getchar();
	system("cls");

	// 1���� �Է��ϸ� �������� ����
	if (Num == 1) playSpeedGugu(nPlay);
	// 2���� �Է��ϸ� ���ǵ� �� �ڸ��� ���� ������ ����
	else if (Num == 2) playMultiplication(nPlay);
	// �� ���� ���ڸ� �Է��ϸ� �ش� ������ �ڸ��� ������ ����
	else playSpeedAddition(nPlay, Num);

}
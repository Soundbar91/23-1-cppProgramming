#include "noWarGame.h"

void main() {
	
	// �÷��̾� ��, ���� �߼�, �Ѿ��� ������ ������ ������ ����
	int nTurn, nGun, nBullets = 0;
	// ���� �����⿡ ���� ���� �õ� ���� ����
	srand((unsigned)time(NULL));

	// �÷��̾� ��, ���� �߼�, �Ѿ��� ������ ����ڷκ��� �Է��� �޴´�.
	printf("���� �ο��� �Է��Ͻÿ� ( �� : 2 ) == > ");
	scanf_s("%d", &nTurn);
	printf("�� ���� ���� ��� �� ������ �Է��Ͻÿ� == > ");
	scanf_s("%d", &nGun);
	printf("����� �Ѿ��� ������ �Է��Ͻÿ� (%d �̸�) == > ", nGun);
	scanf_s("%d", &nBullets);
	getchar();

	// ���þȷ귿 �Լ� ȣ��
	playRussianRoulette( nTurn , nGun , nBullets);
	printf("������ ����ƽ��ϴ�.");

}
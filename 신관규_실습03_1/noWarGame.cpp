#include "noWarGame.h"

void playRussianRoulette(int nTurns, int nGun, int nBullets) {
	
	// �Ѿ˿� ���� �÷��̾ �����ϱ� ���� �迭�� ���� ����
	int People[100] = { 0 };

	// rand �Լ��� �����ؼ� 0���� �Է¹��� �÷��̾��� ������ �������� ���� �߻�
	int People_Number = rand() % nTurns;
	printf("\n\n���� ���Ƚ��ϴ�. %d������ �����մϴ�.\n", People_Number + 1);

	// �ݺ����� �̿��Ͽ� �Ѿ��� �� �߻�� ������ ������ ����
	while ( nBullets != 0) {
		
		// rand�Լ��� �̿��Ͽ� 0���� (�Է¹��� ���� �߼� - 1)���� �������� ���� �߻�
		int pos = rand() % nGun;
		
		printf("[%d��]\tźâ�� �������� ���Ƚ��ϴ�.\n", People_Number + 1);
		printf("\t���͸� ������ �ݹߵ˴ϴ�...");
		getchar();

		// �ܼ�ȭ�� ���� �Ѿ��� �Է¹��� ������ ������������ ��ź �ƴٰ� ����
		// ���� �Է¹��� �Ѿ��� ���� pos�� ����� ������ ������ �ƿ�
		// nBullets�� ������ ���� ���� �Ѿ��� ������ ����
		// ����, �ƿ��� �÷��̾�� ����Ǵ� ���ӿ��� ���ܵǾ� �ϹǷ�, �ش��ϴ� ��ȣ�� �迭�� 1�� ����
		if (pos == nBullets) {
			printf("\t%d�� �����ڰ� �ѿ� �¾ҽ��ϴ�.\n", People_Number + 1);
			People[People_Number + 1] += 1;
			nBullets -= 1;
		}
		else {
			printf("\t��~~~ ��ҽ��ϴ�!!!\n");
		}

		People_Number = (People_Number + 1) % nTurns;

		// ���� �÷��̾ �ش�Ǵ� �迭�� ���� 1�̸� ���ܸ� ���Ѿ� ��
		// �ݺ����� �̿��ؼ� 0�� �� ������ ��ȣ�� ����
		while (People[People_Number + 1] == 1) {
			People_Number = (People_Number + 1) % nTurns;
		}

	}

	printf("\n\n\n");
	for (int i = 1; i < 100; i++) if (People[i] == 1) printf("---->%d�� �����ڰ� �ѿ� �¾ҽ��ϴ�.\n", i);
}
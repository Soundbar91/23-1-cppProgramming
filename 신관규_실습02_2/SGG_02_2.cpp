#include <cstdio>

void main() {

	// Find Pi Approximate Value
	int Num = 0;
	double Result = 0;

	// ������ �Է¹޴´�.
	printf("������ �Է��Ͻÿ� : ");
	scanf_s("%d", &Num);

	// �ݺ����� �̿��ؼ� �Է¹��� �������� ���� i�� ������Ų��.
	for (int i = 1; i <= Num; i++) {

		// ���ǹ��� �̿��Ͽ� 1, ¦��, Ȧ�� �϶� ������ �޸��Ͽ� ������� Result�� �����Ѵ�.
		if (i == 1) {
			Result += 1.0 / 1.0;
		}
		else if ( i % 2 == 0 ) {
			Result -= 1.0 /( 2.0 * (double)i - 1.0);
		}
		else if ( i % 2 != 0 ) {
			Result += 1.0 / (2.0 * (double)i - 1.0);
		}
		
	}

	// �������� 4�� ���ϰ� ������� ����Ѵ�.
	Result *= 4.0;
	printf("%lf", Result);
}
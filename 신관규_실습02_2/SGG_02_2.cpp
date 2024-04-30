#include <cstdio>

void main() {

	// Find Pi Approximate Value
	int Num = 0;
	double Result = 0;

	// 정수를 입력받는다.
	printf("정수를 입력하시오 : ");
	scanf_s("%d", &Num);

	// 반복문을 이용해서 입력받은 정수까지 변수 i를 증가시킨다.
	for (int i = 1; i <= Num; i++) {

		// 조건문을 이용하여 1, 짝수, 홀수 일때 계산식을 달리하여 결과값을 Result에 저장한다.
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

	// 마지막에 4를 곱하고 결과값을 출력한다.
	Result *= 4.0;
	printf("%lf", Result);
}
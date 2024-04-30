#include <cstdio>

void main() {

	/*
	// My School Num = 2020136073

	// 첫 번째 반복문 : 출력하는 숫자의 최솟값 조정
	for (int i = 0; i <= 5; i++) {
		// 두 번째 반복문 : 숫자를 출력
		for (int j = 5; j > i; j--) {
			printf("%d ", j);
		}
		printf("\n");
	}
	*/

	int sum = 0, n = 1;
	while (n++ < 5) { 
		sum += n;
		printf("%d\n", sum);
	}

	
}
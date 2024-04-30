#include <stdio.h>
#include <conio.h>

void main() {

	// Guessing Numbers
	int Num = 0, Min = 1, Max = 999, Guess = 0, Score = 100;

	// 숫자 3자를 입력받는다.
	printf("세 자리 수 입력(1 ~ 999) : ");

	// 입력 받은 각 자리 숫자를 문자 형태로 입력받아 저장한다.
	char Hundred = _getch();
	printf(">");
	char Ten = _getch();
	printf("_");
	char One = _getch();
	printf("<\n\n");

	// 아스키 코드를 이용하여 문자 형태로 입력받은 것을 숫자로 저장한다.
	Num = (Hundred - '0') * 100 + (Ten - '0') * 10 + (One - '0');

	printf("실패 시 -2점, 기회는 총 50번\n\n");

	// 반복문을 이용해서 숫자를 입력받는다.
	for (int i = 1; i <= 50; i++) {

		printf("현재 점수 : %3d\n", Score);
		printf("[%2d]회 %3d ~ %3d 사이의 값 예측 => ", i-1, Min, Max);
		
		char Hundred = _getch();
		printf(")");
		char Ten = _getch();
		printf("_");
		char One = _getch();
		printf("(");

		Guess = (Hundred - '0') * 100 + (Ten - '0') * 10 + (One - '0');

		// 만약 숫자를 맞추면 반복문을 탈출한다.
		if (Num == Guess) break;

		// 정답보다 작은 숫자를 입력하면 그 숫자를 변수 Min에 저장하여 범위를 좁힌다.
		else if (Num > Guess) {
			printf(" 더 큰 숫자입니다 ! \n");
			Min = Guess;
			Score -= 2;
		}

		// 정답보다 큰 숫자를 입력하면 그 숫자를 변수 Max에 저장하여 범위를 좁힌다.
		else {
			printf(" 더 작은 숫자입니다 ! \n");
			Max = Guess;
			Score -= 2;
		}

	}

	// 최종 결과와 점수를 출력한다.
	printf("\n\n\n %s !!! 정답은 %d\n", (Num == Guess) ? "성공" : "실패", Num);
	printf(" 최종 점수 = %d\n", Score);
}
#include <cstdio>

// Multiplication Table Function - Structured Programming
void Multiplication_Table( int Dan ) {
	for (int i = 1; i <= 9; i++) {
		printf("%2d x %2d = %2d\n", Dan, i, Dan * i);
	}
}

class Multiplication {

	private:
		int	from;
		int to;
    public:
		Multiplication() { set(1, 9); };
		~Multiplication() {};
		void set(int f, int t) { from = f, to = t; }
		void play(int dan) {
			for (int i = from; i <= to; i++) {
				printf("%2d x %2d = %2d\n", dan, i, dan * i);
				}
		}
};

void main() {

	// Multiplication Table - Procedural Programming
	int Num = 1;
	int Dan = 2;

	printf("[절차적 프로그래밍]\n");
	printf(" 구구단 2~9단\n");

loop:
	printf("%2d x %2d = %2d\n", Dan, Num, Dan * Num);
	Num++;
	if (Num <= 9) goto loop;
	else if (Num > 9)
	{
		if (Dan == 9) goto second;

		Num = 1;
		Dan++;
		printf("\n");
		goto loop;
	}

second:
	// Multiplication Table - Structured Programming
	printf("\n[구조적 프로그래밍]\n");
	printf(" 구구단 2~9단\n");
	for (int i = 2; i <= 9; i++) {
		Multiplication_Table(i);
		printf("\n");
	}

	// Multiplication Table - Object-oriented Programming
	printf("\n[객체지향 프로그래밍]\n");
	printf(" 구구단 2~9단\n");

	Multiplication myGame;
	for (int i = 2; i <= 9; i++) {
		myGame.play(i);
		printf("\n");
	}
}
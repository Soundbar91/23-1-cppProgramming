#include "Hangman.h"
#include <time.h>
#include <stdlib.h>

int main() {

	// 난수 발생을 위한 초기화
	srand((unsigned int)time(NULL));

	// Word.txt에 저장된 단어 100개를 저장할 문자열 배열을 선언
	string Word[100];
	
	// 파일을 읽기 위한 객체 f1를 만든다.
	ifstream f1("Word.txt");
	// 반복문을 이용하여 텍스트 파일에서 한 줄씩 읽어와 Word 문자열 배열에 저장한다.
	if (f1) {
		for (int i = 0; i < 100; i++) getline(f1, Word[i]);
	}
	f1.close();
	
	// clss Hangman를 자료형으로 하는 Game 객체 선언
	Hangman Game;

	// 0 ~ 99까지 난수를 발생하고 문자열 배열 Word에서 해당하는 난수의 문자를 Game 클래스의 Play 함수로 전달한다.
	int Num = rand() % 100;
	Game.Play(Word[Num]);

	return 0;
}
#include "Hangman.h"
#include <time.h>
#include <stdlib.h>

int main() {

	// ���� �߻��� ���� �ʱ�ȭ
	srand((unsigned int)time(NULL));

	// Word.txt�� ����� �ܾ� 100���� ������ ���ڿ� �迭�� ����
	string Word[100];
	
	// ������ �б� ���� ��ü f1�� �����.
	ifstream f1("Word.txt");
	// �ݺ����� �̿��Ͽ� �ؽ�Ʈ ���Ͽ��� �� �پ� �о�� Word ���ڿ� �迭�� �����Ѵ�.
	if (f1) {
		for (int i = 0; i < 100; i++) getline(f1, Word[i]);
	}
	f1.close();
	
	// clss Hangman�� �ڷ������� �ϴ� Game ��ü ����
	Hangman Game;

	// 0 ~ 99���� ������ �߻��ϰ� ���ڿ� �迭 Word���� �ش��ϴ� ������ ���ڸ� Game Ŭ������ Play �Լ��� �����Ѵ�.
	int Num = rand() % 100;
	Game.Play(Word[Num]);

	return 0;
}
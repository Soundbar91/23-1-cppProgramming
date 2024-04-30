#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

// cin, coun�� ����ϱ����� �̸� ���� std�� ����
using namespace std;

// ��� ������ ���� ����� class
class Hangman {

	// private ��� ������ ����
	// �� �ܰ躰 ȭ���� ����ϱ� ���� ���ڿ� �迭
	string Progress[64];
	// ������ �����ϴ� ���ڿ�
	string Problem;
	// ������ ���ڸ� �����ϴ� ���ڿ�
	string Answer;
	// ��ü ���ĺ��� ���� ��Ȳ�� �����ϴ� ���ڿ�
	string Guessed;
	// ���� Ƚ���� �����ϴ� ����
	int nTries = 0;
	// �ִ� ����Ƚ���� ��� ���������� ����
	const int Max_Tries = 7;

	// HangmanProgress���� ���ڿ��� �о���� ���� �Լ��� private ��� �Լ��� ����
	// �Ű������� ����Ʈ ���� �༭ �Լ��� ȣ���� �� �Ű������� ���� ���δ�.
	void Load(const char* ProgName = "HangmanProgress.txt") {

		// ������ �б� ���� ��ü fs�� �����.
		ifstream fs(ProgName);

		// �ݺ����� �̿��Ͽ� �ؽ�Ʈ ���Ͽ��� �� �پ� �о�� Progress ���ڿ� �迭�� �����Ѵ�.
		if (fs) for (int i = 0; i < 64; i++) getline(fs, Progress[i]);

	}

	// ȭ���� ����ϱ� ���� �Լ��� private ��� �Լ��� ����
	void Print() {

		system("cls");
		cout << " <Hangman Game>\n";
		
		// nTries�� ���� ��µǴ� ȭ���� �ٸ� -> nTrise = 1 -> Progress[8] ~ Progress[15]
		// �ݺ����� �̿��Ͽ� Progress�� ����� ���ڿ��� ���
		for (int i = 0; i < 8; i++) cout << '\t' << Progress[nTries * 8 + i] << endl;
		cout << "\n\t" << Answer;
		cout << "\n\n " << Guessed;

	}

	// �Է��� ���ĺ��� ���信 �� �� ��Ÿ�������� ã�� ȸ���� ��ȯ�ϴ� �Լ��� private ��� �Լ��� ����
	int CountMatched(char ch) {
		
		// Problem�� ����� ���信 �Է��� ���ڰ� �� �� �� �ִ��� ������ ����
		int nMatched = 0;
		
		// �ݺ����� �̿��Ͽ� �˻縦 �Ѵ�. 
		for (int pos = -1; ;) {
			// string�� find �Լ��� �̿��ؼ� Problem ���ڿ����� pos + 1 �ε��� ���� �Ű������� ����� ���ڸ� ã�´�.
			// ã�� �Ǹ� �ش� ��ġ�� pos�� �����Ѵ�.
			pos = Problem.find(ch, pos + 1);

			// ã�� ���ϸ� pos�� -1�̹Ƿ� �ݺ����� Ż���Ѵ�.
			if (pos < 0) break;
			// ������ Answer pos �ε����� �����Ѵ�.
			Answer[pos] = ch;
			nMatched++;
		}

		return nMatched;
	}

	// ���ڸ� �о� �������� �ƴ��� �Ǵ��ϴ� �Լ��� private ��� �Լ��� ����
	void Guess() {
		
		// ���ڸ� �Է¹޾� ch�� �����Ѵ�.
		char ch = _getch();

		// ���ǹ��� �̿��Ͽ� ���ĺ��� �������� �������� �Է¹޾��� �� ������ ����.
		if (ch >= 'a' && ch <= 'z') {

			// string�� find �Լ��� �̿��Ͽ� Guessed�� �Է��� ���ĺ��� �ִ��� ã�´�.
			int pos = Guessed.find(ch);

			// Guessed ���ڿ��� �������� ������(pos�� ����) ������ ����.
			if (pos < 0) {
				// Guessed ���ڿ��� �ش� ��ġ���� �Է¹��� ���ĺ����� �ٲ۴�.
				Guessed[ch - 'a'] = ch;
				// CountMatched �Լ��� ���� ���信 �Է¹��� ���ĺ��� ��� �������� �˻��Ѵ�.
				// CountMatched �Լ��� ��ȯ ���� 0�� ��쿡�� ���信 �ش� ���ĺ��� ���ٴ� ������ nTries�� ������Ų��.
				if (CountMatched(ch) == 0) nTries++;
			}

		}

	}

public:

	// ��� ������ �� �Լ��� public ��� �Լ��� ����
	void Play(string prob) {
		
		// HangmanProgress.txt�� ����� ���ڸ� ��� �о� �´�.
		Load();
		// ���ڿ� Problem ������ �Ű������� ���޹��� prob�� �����Ѵ�.
		Problem = prob;
		// ���ڿ� Anwer�� Problem�� ���� ��ŭ '-'�� �����Ѵ�.
		Answer = string(Problem.length(), '-');
		// ���ڿ� Guessed�� 26�� '-'�� �����Ѵ�.
		Guessed = string(26, '-');

		// �ݺ����� �̿��Ͽ� ������ �����Ѵ�.
		// ���� Ƚ���� �ִ� ����Ƚ������ Ŀ���� ������ Ʋ���� �ݺ����� Ż��
		while (nTries < Max_Tries && Answer != Problem) {
			Print();
			Guess();
		}
		
		// ���� �����ڸ� ����Ͽ� ���п� ������ ���
		Print();
		cout << "\n\t" << ((nTries == Max_Tries) ? "����" : "����") << endl;
	}

};
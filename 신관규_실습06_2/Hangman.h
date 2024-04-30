#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

// cin, coun를 사용하기위해 이름 공간 std를 선언
using namespace std;

// 행맨 게임을 위해 선언된 class
class Hangman {

	// private 멤버 변수로 선언
	// 각 단계별 화면을 출력하기 위한 문자열 배열
	string Progress[64];
	// 정답을 저장하는 문자열
	string Problem;
	// 예측한 문자를 저장하는 문자열
	string Answer;
	// 전체 알파벳의 예측 상황을 저장하는 문자열
	string Guessed;
	// 실패 횟수를 저장하는 변수
	int nTries = 0;
	// 최대 실패횟수를 상수 정수형으로 선언
	const int Max_Tries = 7;

	// HangmanProgress에서 문자열을 읽어오기 위한 함수를 private 멤버 함수로 선언
	// 매개변수에 디폴트 값을 줘서 함수를 호출할 때 매개변수의 수를 줄인다.
	void Load(const char* ProgName = "HangmanProgress.txt") {

		// 파일을 읽기 위한 객체 fs를 만든다.
		ifstream fs(ProgName);

		// 반복문을 이용하여 텍스트 파일에서 한 줄씩 읽어와 Progress 문자열 배열에 저장한다.
		if (fs) for (int i = 0; i < 64; i++) getline(fs, Progress[i]);

	}

	// 화면을 출력하기 위한 함수를 private 멤버 함수로 선언
	void Print() {

		system("cls");
		cout << " <Hangman Game>\n";
		
		// nTries에 따라 출력되는 화면이 다름 -> nTrise = 1 -> Progress[8] ~ Progress[15]
		// 반복문을 이용하여 Progress에 저장된 문자열을 출력
		for (int i = 0; i < 8; i++) cout << '\t' << Progress[nTries * 8 + i] << endl;
		cout << "\n\t" << Answer;
		cout << "\n\n " << Guessed;

	}

	// 입력한 알파벳이 정답에 몇 번 나타나는지를 찾아 회수를 반환하는 함수를 private 멤버 함수로 선언
	int CountMatched(char ch) {
		
		// Problem에 저장된 정답에 입력한 문자가 몇 번 들어가 있는지 저장할 변수
		int nMatched = 0;
		
		// 반복문을 이용하여 검사를 한다. 
		for (int pos = -1; ;) {
			// string의 find 함수를 이용해서 Problem 문자열에서 pos + 1 인덱스 부터 매개변수에 저장된 문자를 찾는다.
			// 찾게 되면 해당 위치를 pos에 저장한다.
			pos = Problem.find(ch, pos + 1);

			// 찾지 못하면 pos는 -1이므로 반복문을 탈출한다.
			if (pos < 0) break;
			// 정답을 Answer pos 인덱스에 저장한다.
			Answer[pos] = ch;
			nMatched++;
		}

		return nMatched;
	}

	// 문자를 읽어 정답인지 아닌지 판단하는 함수를 private 멤버 함수로 선언
	void Guess() {
		
		// 문자를 입력받아 ch에 저장한다.
		char ch = _getch();

		// 조건문을 이용하여 알파벳이 정상적인 범위에서 입력받았을 때 루프에 들어간다.
		if (ch >= 'a' && ch <= 'z') {

			// string의 find 함수를 이용하여 Guessed에 입력한 알파벳이 있는지 찾는다.
			int pos = Guessed.find(ch);

			// Guessed 문자열에 존재하지 않으면(pos가 음수) 루프에 들어간다.
			if (pos < 0) {
				// Guessed 문자열에 해당 위치값을 입력받은 알파벳으로 바꾼다.
				Guessed[ch - 'a'] = ch;
				// CountMatched 함수를 통해 정답에 입력받은 알파벳이 몇번 나오는지 검사한다.
				// CountMatched 함수의 반환 값이 0인 경우에는 정답에 해당 알파벳이 없다는 뜻으로 nTries를 증가시킨다.
				if (CountMatched(ch) == 0) nTries++;
			}

		}

	}

public:

	// 행맨 게임의 주 함수를 public 멤버 함수로 선언
	void Play(string prob) {
		
		// HangmanProgress.txt에 저장된 문자를 모두 읽어 온다.
		Load();
		// 문자열 Problem 변수에 매개변수로 전달받은 prob를 저장한다.
		Problem = prob;
		// 문자열 Anwer에 Problem의 길이 만큼 '-'를 저장한다.
		Answer = string(Problem.length(), '-');
		// 문자열 Guessed에 26의 '-'를 저장한다.
		Guessed = string(26, '-');

		// 반복문을 이용하여 게임을 진행한다.
		// 실패 횟수가 최대 실패횟수보다 커지고 정답이 틀리면 반복문을 탈출
		while (nTries < Max_Tries && Answer != Problem) {
			Print();
			Guess();
		}
		
		// 삼항 연산자를 사용하여 실패와 정답을 출력
		Print();
		cout << "\n\t" << ((nTries == Max_Tries) ? "실패" : "정답") << endl;
	}

};
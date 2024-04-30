#pragma once // 해당 헤더 파일이 한번만 빌드되도록 한다.
#include <iostream>
#include <iomanip>

// Matrix 클래스 선언
class Matrix {

private:
	// 행과 열의 크기를 선언
	int rows, cols;
	// 동적으로 할당된 메모리의 주소를 가리클 이중 포인터 선언
	int** mat;

public:

	// Matrix 클래스의 생성자
	// 행과 열의 크기를 인수로 받아 동적으로 행렬을 생성한다.
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(NULL) {

		// 입력 받은 열의 크기 만큼 1차원 배열을 동적으로 할당한다.
		mat = new int* [rows];
		// 반복문을 이용하여 입력 받은 행의 크기 만큼 동적으로 할당 후 각 행 데이터의 주소를 포인터 배열에 저장
		for (int i = 0; i < rows; i++) {
			mat[i] = new int[cols];
		}

	}

	// Matrix 클래스의 소멸자
	~Matrix() {

		// 동적으로 할당 된 행의 데이터를 먼저 해제한다.
		if (mat != NULL) {
			for (int i = 0; i < rows; i++) {
				delete[] mat[i];
			}
			// 이후 동적으로 할당 된 열의 데이터를 해제한다.
			delete[] mat;
		}

	}

	// 각 항목에 접근할 수 있도록 하는 참조자 함수
	int& elem(int x, int y) { return mat[y][x]; }
	// 열의 크기를 반환하는 함수
	int Rows() { return rows; }
	// 행의 크기를 반환하는 함수
	int Cols() { return cols; }
	// 이중 포인터 mat을 반환하는 이중 포인터 함수
	int** Data() { return mat; };

	// 화면에 행렬의 내용을 출력하는 함수
	void print(const char* str = "Mat") {
		
		// 전달 받은 문자와 행렬의 크기를 출력
		cout << str << " " << rows << "x" << cols << endl;
		// 반복문을 이용하여 화면에 행렬의 내용을 출력 
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << setw(4) << mat[i][j];
			}
			cout << "\n";
		}

	}

	// 행렬의 각 항목들을 난수로 초기화 하는 함수
	void setRand(int val = 100) {

		if (mat != NULL) {
			// 반복문을 이용하여 0 ~ val - 1 까지의 난수로 행렬를 초기화한다.
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					mat[i][j] = (rand() % val);
				}
			}
		}

	}

};
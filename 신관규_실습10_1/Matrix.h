#pragma once // �ش� ��� ������ �ѹ��� ����ǵ��� �Ѵ�.
#include <iostream>
#include <iomanip>

// Matrix Ŭ���� ����
class Matrix {

private:
	// ��� ���� ũ�⸦ ����
	int rows, cols;
	// �������� �Ҵ�� �޸��� �ּҸ� ����Ŭ ���� ������ ����
	int** mat;

public:

	// Matrix Ŭ������ ������
	// ��� ���� ũ�⸦ �μ��� �޾� �������� ����� �����Ѵ�.
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(NULL) {

		// �Է� ���� ���� ũ�� ��ŭ 1���� �迭�� �������� �Ҵ��Ѵ�.
		mat = new int* [rows];
		// �ݺ����� �̿��Ͽ� �Է� ���� ���� ũ�� ��ŭ �������� �Ҵ� �� �� �� �������� �ּҸ� ������ �迭�� ����
		for (int i = 0; i < rows; i++) {
			mat[i] = new int[cols];
		}

	}

	// Matrix Ŭ������ �Ҹ���
	~Matrix() {

		// �������� �Ҵ� �� ���� �����͸� ���� �����Ѵ�.
		if (mat != NULL) {
			for (int i = 0; i < rows; i++) {
				delete[] mat[i];
			}
			// ���� �������� �Ҵ� �� ���� �����͸� �����Ѵ�.
			delete[] mat;
		}

	}

	// �� �׸� ������ �� �ֵ��� �ϴ� ������ �Լ�
	int& elem(int x, int y) { return mat[y][x]; }
	// ���� ũ�⸦ ��ȯ�ϴ� �Լ�
	int Rows() { return rows; }
	// ���� ũ�⸦ ��ȯ�ϴ� �Լ�
	int Cols() { return cols; }
	// ���� ������ mat�� ��ȯ�ϴ� ���� ������ �Լ�
	int** Data() { return mat; };

	// ȭ�鿡 ����� ������ ����ϴ� �Լ�
	void print(const char* str = "Mat") {
		
		// ���� ���� ���ڿ� ����� ũ�⸦ ���
		cout << str << " " << rows << "x" << cols << endl;
		// �ݺ����� �̿��Ͽ� ȭ�鿡 ����� ������ ��� 
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << setw(4) << mat[i][j];
			}
			cout << "\n";
		}

	}

	// ����� �� �׸���� ������ �ʱ�ȭ �ϴ� �Լ�
	void setRand(int val = 100) {

		if (mat != NULL) {
			// �ݺ����� �̿��Ͽ� 0 ~ val - 1 ������ ������ ��ĸ� �ʱ�ȭ�Ѵ�.
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					mat[i][j] = (rand() % val);
				}
			}
		}

	}

};
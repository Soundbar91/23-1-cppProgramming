#pragma once
#include <string>

// ���� ����¿��� �߻��ϴ� ���� ������ �����ϴ� Ŭ����
struct FileException {

	// ������ �̸��� �б� ���� ���� ��带 ������ bool ������ ��� ������ �����Ѵ�.
	string Filename;
	bool bRead;
	
	// FileException�� ������
	FileException(string name, bool b) : Filename(name), bRead(b) {}
};
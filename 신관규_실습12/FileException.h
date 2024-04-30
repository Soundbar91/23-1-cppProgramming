#pragma once
#include <string>

// 파일 입출력에서 발생하는 예외 정보를 저장하는 클래스
struct FileException {

	// 파일의 이름과 읽기 모드와 쓰기 모드를 구별할 bool 변수를 멤버 변수로 선언한다.
	string Filename;
	bool bRead;
	
	// FileException의 생성자
	FileException(string name, bool b) : Filename(name), bRead(b) {}
};
#include "MonsterWorld.h"
#include <time.h>

int main() {

	srand((unsigned int)time(NULL));
	// ���� ���� ũ�⸦ �����ϱ� ���� ���� ����
	int w = 16, h = 8;

	// MonsterWorld ������ ���� ũ�⸦ �ѱ��. 
	MonsterWorld game(w, h);

	// Monster Ŭ������ ���� ��ü�� ����
	// MonsterWorld Ŭ������ Add�Լ��� ���� ��ü�� �̿��Ͽ� ���͸� �߰��Ѵ�.
	game.Add( new Monster("����", "��", rand() % w, rand() % h));
	game.Add( new Monster("������", "��", rand() % w, rand() % h));
	game.Add( new Monster("���״�", "��", rand() % w, rand() % h));
	game.Add( new Monster("��Ʈ", "��", rand() % w, rand() % h));
	// MonsterWorld Ŭ������ Play �Լ��� �ִ� �̵� ȸ���� �����ð��� �ѱ�鼭 ������ ������ �ȴ�.
	game.Play(100, 100);
	printf("------���� ����-----------------------\n");

	return 0;

}
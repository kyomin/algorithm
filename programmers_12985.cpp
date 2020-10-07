#include <iostream>

using namespace std;

bool isFighting(int a, int b) {
	// a�� ¦��, b�� Ȧ���� ���
	if (a % 2 == 0 && b % 2 == 1)
		if (a - b == 1)
			return true;

	// b�� ¦��, a�� Ȧ���� ���
	if (b % 2 == 0 && a % 2 == 1)
		if (b - a == 1)
			return true;

	return false;
}

int solution(int n, int a, int b) {
	int answer = 1;

	while (true) {
		// ���� �ٰ� �Ǵ� ���� Ż��
		if (isFighting(a, b))
			break;

		// ���� ���� ������ ��ȣ �ο�
		if (a % 2 == 0)
			a /= 2;
		else
			a = (a + 1) / 2;

		if (b % 2 == 0)
			b /= 2;
		else
			b = (b + 1) / 2;

		answer++;
	}

	return answer;
}
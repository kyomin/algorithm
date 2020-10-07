#include <iostream>

using namespace std;

bool isFighting(int a, int b) {
	// a가 짝수, b가 홀수인 경우
	if (a % 2 == 0 && b % 2 == 1)
		if (a - b == 1)
			return true;

	// b가 짝수, a가 홀수인 경우
	if (b % 2 == 0 && a % 2 == 1)
		if (b - a == 1)
			return true;

	return false;
}

int solution(int n, int a, int b) {
	int answer = 1;

	while (true) {
		// 서로 붙게 되는 순간 탈출
		if (isFighting(a, b))
			break;

		// 각각 다음 라운드의 번호 부여
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
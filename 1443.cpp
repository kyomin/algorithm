#include <iostream>

using namespace std;

int ans = 1;			// 처음엔 1
int curOperCnt = 0;		// 연산 횟수
bool foundAns = false;	// 답을 찾았는가?
int D, P;

// 자릿수 계산
int calcDigits(int num) {
	int result = 0;

	while (num != 0) {
		num /= 10;
		result++;
	}

	return result;
}

void dfs() {
	// P회의 연산을 했다면
	if (curOperCnt == P) {
		// 연산 결과가 D자리를 넘기지 않는다면
		if (calcDigits(ans) <= D) 
			foundAns = true;

		return;
	}

	for (int i = 9; i >= 2; i--) {
		ans *= i;
		curOperCnt++;

		dfs();

		if (foundAns)
			return;

		ans /= i;
		curOperCnt--;
	}
}

int main() {
	cin >> D >> P;

	dfs();

	if (foundAns) {
		cout << ans << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}
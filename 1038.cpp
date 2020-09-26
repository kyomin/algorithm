#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const int MAX = 1000000;

int N;
int idx = 9;	// 1 ~ 9는 이미 감소수라고 여김
queue <ll> q;
ll descending[MAX + 1];		// N번째 감소 수를 담는다.

void preCalculate() {
	while (idx <= N) {
		if (q.empty())
			return;

		// 큐에 있는 감소수를 꺼낸다.
		ll descendingNum = q.front();
		q.pop();

		// 마지막 자리 숫자를 확인
		int lastNum = descendingNum % 10;

		// 마지막 자리 숫자보다 작은 숫자들을 붙여 나감
		for (int i = 0; i < lastNum; i++) {
			q.push(descendingNum * 10 + i);
			descending[++idx] = descendingNum * 10 + i;
		}
	}
}

int main() {
	cin >> N;

	// 1 ~ 9는 이미 감소하는 수
	for (int i = 1; i <= 9; i++) {
		q.push(i);
		descending[i] = i;
	}

	preCalculate();

	// N이 범위를 초과했을 경우
	if (!descending[N] && N)
		cout << -1 << '\n';
	else  // 정상적인 범위일 경우
		cout << descending[N] << '\n';

	return 0;
}
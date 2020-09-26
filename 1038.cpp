#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const int MAX = 1000000;

int N;
int idx = 9;	// 1 ~ 9�� �̹� ���Ҽ���� ����
queue <ll> q;
ll descending[MAX + 1];		// N��° ���� ���� ��´�.

void preCalculate() {
	while (idx <= N) {
		if (q.empty())
			return;

		// ť�� �ִ� ���Ҽ��� ������.
		ll descendingNum = q.front();
		q.pop();

		// ������ �ڸ� ���ڸ� Ȯ��
		int lastNum = descendingNum % 10;

		// ������ �ڸ� ���ں��� ���� ���ڵ��� �ٿ� ����
		for (int i = 0; i < lastNum; i++) {
			q.push(descendingNum * 10 + i);
			descending[++idx] = descendingNum * 10 + i;
		}
	}
}

int main() {
	cin >> N;

	// 1 ~ 9�� �̹� �����ϴ� ��
	for (int i = 1; i <= 9; i++) {
		q.push(i);
		descending[i] = i;
	}

	preCalculate();

	// N�� ������ �ʰ����� ���
	if (!descending[N] && N)
		cout << -1 << '\n';
	else  // �������� ������ ���
		cout << descending[N] << '\n';

	return 0;
}
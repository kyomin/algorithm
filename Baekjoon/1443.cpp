#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int D, P;
long long maxNum;

/*
	{ num, cnt }, true/false
	cnt Ƚ����ŭ num�� ��������°�?
*/
map<pair<long long, int>, bool> visited;

// �ڸ��� ���ϴ� �Լ�
int getLength(long long num) {
	int result = 0;

	while (num) {
		num /= 10;
		result++;
	}

	return result;
}

void simulation(long long num, int cnt) {
	// ���� ġ�� : ���� Ƚ���� ����� ���� ��� or �ڸ��� ������ �ʰ�
	if (visited.count({ num, cnt }) || getLength(num) > D)
		return;

	visited[{ num, cnt }] = true;

	// ���� Ƚ���� ä���ٸ�
	if (cnt == P) {
		maxNum = max(maxNum, num);
		return;
	}

	for (int i = 2; i <= 9; i++)
		simulation(num*i, cnt + 1);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> D >> P;

	maxNum = -1;
	simulation(1, 0);

	cout << maxNum << '\n';

	return 0;
}
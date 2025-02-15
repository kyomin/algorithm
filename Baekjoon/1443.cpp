#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int D, P;
long long maxNum;

/*
	{ num, cnt }, true/false
	cnt 횟수만큼 num이 만들어졌는가?
*/
map<pair<long long, int>, bool> visited;

// 자릿수 구하는 함수
int getLength(long long num) {
	int result = 0;

	while (num) {
		num /= 10;
		result++;
	}

	return result;
}

void simulation(long long num, int cnt) {
	// 가지 치기 : 연산 횟수와 결과가 같은 경우 or 자릿수 범위를 초과
	if (visited.count({ num, cnt }) || getLength(num) > D)
		return;

	visited[{ num, cnt }] = true;

	// 연산 횟수를 채웠다면
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
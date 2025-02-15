#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int d[61][61][61];
int scv[3] = { 0, };
int N;

int go(int i, int j, int k) {
	if (i < 0) return go(0, j, k);
	if (j < 0) return go(i, 0, k);
	if (k < 0) return go(i, j, 0);

	// 더 이상 공격할 횟수는  0이다(최소해)
	if (i == 0 && j == 0 && k == 0)
		return 0;

	int &ans = d[i][j][k];

	// 이미 답이 구해진 경우라면
	if (ans != -1)
		return ans;

	ans = 1000000;

	vector<int> p = { 1, 3, 9 };

	do {
		ans = min(ans, go(i - p[0], j - p[1], k - p[2]));
	} while (next_permutation(p.begin(), p.end()));

	// 이전 공격 횟수 + 현재 횟수
	ans += 1;

	return ans;
}

int main() {
	cin >> N;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < N; i++)
		cin >> scv[i];

	cout << go(scv[0], scv[1], scv[2]) << '\n';

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define MAX 11

using namespace std;

int N, K;
int dp[MAX] = { 0, };

vector<string> ans;

// ����� �� ���� ã��
void find() {
	queue<string> q;	// Ž���� ���ڸ� ������ ����
	map<string, bool> mp;	// �湮 ����

	// ó���� 1, 2, 3�� �ְ� �湮 ó��
	q.push("1");
	q.push("2");
	q.push("3");
	mp["1"] = true;
	mp["2"] = true;
	mp["3"] = true;

	while (!q.empty()) {
		int sum = 0;	// ������� ���� ������ ��

		// �� ���� ���Ҹ� �̰� ����
		string s = q.front();
		q.pop();

		// ������� ���� ���ڸ� ���Ѵ�.
		for (int i = 0; i < s.size(); i++)
			sum += (int)(s[i] - '0');

		// ������� ���� ���ڰ� N�� ��� ���Ϳ� ����
		if (sum == N) {
			ans.push_back(s);
			continue;
		}

		// ������� ���� ������ ���� ���̰� N���� �� ���� ����
		if (s.size() > N)
			continue;

		// ������ ���ڴ� 1, 2, 3���� �̷����. �� ��θ� Ž��
		for (int i = 1; i <= 3; i++) {
			// ���̰� N�̸� �� �̻� ���ص� N���� Ŀ���� �翬�ϴϱ� ����
			if (s.size() == N)
				continue;

			string temp = s;

			// ������ ���� i�� ����
			temp += (char)('0' + i);

			if (mp.find(temp) == mp.end()) {	// �湮���� ���� ���ڸ�
				q.push(temp);	// ť�� �ְ�
				mp[temp] = true;	// �湮 ó��
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	// 10������ ���ϱ� ������ ã��
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	// N�� ���� �� �ִ� ����� ������ ���� ���� �����
	if (dp[N] < K) {
		cout << -1 << '\n';
		return 0;
	}

	// N�� ���� �� �ִ� ����� �� �ȿ��� �����
	find();		// ���ڸ� ã�´�.
	sort(ans.begin(), ans.end());	// �������� ����

	// N�� ���� K��° ���� +�� �����Ͽ� ���
	for (int i = 0; i < ans[K - 1].size(); i++) {
		cout << ans[K - 1][i];

		if (i == ans[K - 1].size() - 1)
			break;

		cout << "+";
	}

	return 0;
}
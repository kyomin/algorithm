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

// 경우의 수 덧셈 찾기
void find() {
	queue<string> q;	// 탐색할 숫자를 저장할 공간
	map<string, bool> mp;	// 방문 여부

	// 처음엔 1, 2, 3을 넣고 방문 처리
	q.push("1");
	q.push("2");
	q.push("3");
	mp["1"] = true;
	mp["2"] = true;
	mp["3"] = true;

	while (!q.empty()) {
		int sum = 0;	// 현재까지 뽑은 원소의 합

		// 맨 앞의 원소를 뽑고 삭제
		string s = q.front();
		q.pop();

		// 현재까지 뽑은 숫자를 더한다.
		for (int i = 0; i < s.size(); i++)
			sum += (int)(s[i] - '0');

		// 현재까지 뽑은 숫자가 N인 경우 벡터에 삽입
		if (sum == N) {
			ans.push_back(s);
			continue;
		}

		// 현재까지 뽑은 숫자의 합의 길이가 N보다 긴 경우는 무시
		if (s.size() > N)
			continue;

		// 문제의 숫자는 1, 2, 3으로 이루어짐. 각 경로를 탐색
		for (int i = 1; i <= 3; i++) {
			// 길이가 N이면 더 이상 더해도 N보다 커짐은 당연하니까 무시
			if (s.size() == N)
				continue;

			string temp = s;

			// 숫자의 끝에 i를 삽입
			temp += (char)('0' + i);

			if (mp.find(temp) == mp.end()) {	// 방문하지 않은 숫자면
				q.push(temp);	// 큐에 넣고
				mp[temp] = true;	// 방문 처리
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	// 10까지의 더하기 가짓수 찾기
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	// N을 만들 수 있는 경우의 수보다 많은 수를 물어보면
	if (dp[N] < K) {
		cout << -1 << '\n';
		return 0;
	}

	// N을 만들 수 있는 경우의 수 안에서 물어보면
	find();		// 숫자를 찾는다.
	sort(ans.begin(), ans.end());	// 오름차순 정렬

	// N을 만든 K번째 식을 +를 포함하여 출력
	for (int i = 0; i < ans[K - 1].size(); i++) {
		cout << ans[K - 1][i];

		if (i == ans[K - 1].size() - 1)
			break;

		cout << "+";
	}

	return 0;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[55][55];
vector<string> nodes;
int ans = 55;

bool isOneDifferent(string s1, string s2) {
	int cnt = 0;
	int len = s1.size();
	
	for (int i = 0; i < len; i++)
		if (s1[i] != s2[i]) cnt++;

	if (cnt == 1)
		return true;
	else
		return false;
}

void dfs(int node, int cnt, string target) {
	if (nodes[node] == target) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = 0; i < nodes.size(); i++) {
		int next = i;

		if (next == node) continue;
		if (check[node][next]) continue;

		// 한 글자만 다른 경우에 탐색 진행
		if (isOneDifferent(nodes[node], nodes[next])) {
			check[node][next] = true;
			check[next][node] = true;

			dfs(next, cnt + 1, target);
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	bool flag = false;

	for (int i = 0; i < words.size(); i++)
		if (words[i] == target)
			flag = true;

	if (!flag) return 0;

	nodes.push_back(begin);

	for (int i = 0; i < words.size(); i++)
		nodes.push_back(words[i]);

	dfs(0, 0, target);

	answer = ans;

	return answer;
}
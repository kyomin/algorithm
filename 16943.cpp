#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

priority_queue<int, vector<int>, less<int>> maxPQ;

vector<char> vc;

bool visit[10];

string A;
int B, M;

void dfs() {
	if (vc.size() == M) {
		// 첫 숫자가 0이면 수를 만들 수 없다.
		if (vc[0] == '0') 
			return;
		
		string num = "";

		for (auto c : vc) {
			num += c;
		}

		maxPQ.push(atoi(num.c_str()));

		return;
	}

	for (int i = 0; i < M; i++) {
		if (!visit[i]) {
			visit[i] = true;
			vc.push_back(A[i]);

			dfs();

			vc.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	cin >> A >> B;
	M = A.size();

	dfs();

	int ans = -1;

	while (!maxPQ.empty()) {
		int num = maxPQ.top();
		maxPQ.pop();

		if (num <= B) {
			ans = num;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<int> ans;	// 실제 답
vector<int> myAns;	// 내가 찍은 답

void dfs(int depth) {
	// 10문제 다 찍었다면
	if (depth == 10) {
		int sum = 0;
		for (int i = 0; i < 10; i++)
			if (ans[i] == myAns[i])
				sum += 1;

		// 5점 이상인 경우에 카운트 증가
		if (sum >= 5)
			cnt++;

		return;
	}

	// 1~5까지 찍는다.
	for (int i = 1; i <= 5; i++) {
		// 3개 연속된 문제의 답이 같은 경우
		if (depth > 1 && myAns[depth - 2] == myAns[depth - 1] && myAns[depth - 1] == i)
			continue;

		myAns.push_back(i);
		dfs(depth + 1);
		myAns.pop_back();
	}
}

int main() {
	ans.resize(10);
	for (int i = 0; i < 10; i++)
		cin >> ans[i];

	dfs(0);

	cout << cnt << endl;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<int> ans;	// ���� ��
vector<int> myAns;	// ���� ���� ��

void dfs(int depth) {
	// 10���� �� ����ٸ�
	if (depth == 10) {
		int sum = 0;
		for (int i = 0; i < 10; i++)
			if (ans[i] == myAns[i])
				sum += 1;

		// 5�� �̻��� ��쿡 ī��Ʈ ����
		if (sum >= 5)
			cnt++;

		return;
	}

	// 1~5���� ��´�.
	for (int i = 1; i <= 5; i++) {
		// 3�� ���ӵ� ������ ���� ���� ���
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
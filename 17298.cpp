#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	vector<int> ans(N, 0);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	stack<int> st;
	st.push(0);

	for (int i = 1; i < N; i++) {
		// ������ ���� �ʰ� ���� ������ ���� top ��ġ�� ������ ũ��
		while (!st.empty() && A[st.top()] < A[i]) {
			ans[st.top()] = A[i];
			st.pop();
		}

		st.push(i);
	}

	while (!st.empty()) {
		ans[st.top()] = -1;
		st.pop();
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";

	return 0;
}
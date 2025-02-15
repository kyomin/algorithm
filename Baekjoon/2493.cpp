#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	stack<pair<int, int>> st;	// first: height, second: index
	vector<int> tops;
	vector<int> ans;
	int N;
	cin >> N;

	tops.resize(N);
	
	for (int i = 0; i < N; i++)
		cin >> tops[i];

	for (int i = 1; i <= N; i++) {
		int value = tops[i - 1];

		while (!st.empty()) {
			if (value < st.top().first) {
				ans.push_back(st.top().second);
				break;
			}

			st.pop();
		}

		if (st.size() == 0)
			ans.push_back(0);

		st.push(make_pair(value, i));
	}

	for (int i = 0; i < N - 1; i++)
		cout << ans[i] << ' ';
	
	cout << ans[N - 1] << endl;

	return 0;
}
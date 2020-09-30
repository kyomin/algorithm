#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 결과들
vector<vector<int>> results;
int N;

bool cmp(const vector<int> &v1, const vector<int> &v2) {
	if (v1.size() > v2.size())
		return true;
	else
		return false;
}

// 규칙에 따라 수열을 만든다.
void makeArr(vector<int>& v) {
	int startIdx = 1;
	int num = v[0] - v[1];

	// 음수가 되기 전까지 작업한다.
	while (num >= 0) {
		v.push_back(num);
		startIdx++;

		num = v[startIdx - 1] - v[startIdx];
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int start = N / 2; start <= N; start++) {
		vector<int> result;
		result.push_back(N);
		result.push_back(start);

		makeArr(result);

		results.push_back(result);
	}

	sort(results.begin(), results.end(), cmp);

	vector<int> result = results[0];

	int len = result.size();

	cout << len << '\n';

	for (int i = 0; i < len; i++)
		cout << result[i] << ' ';

	cout << '\n';

	return 0;
}
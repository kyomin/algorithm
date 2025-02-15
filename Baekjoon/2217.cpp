#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool descent(const int &num1, const int &num2) {
	if (num1 > num2)
		return true;
	else
		return false;
}

int main() {
	vector<int> ropes;
	int ans = 0;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int rope;
		cin >> rope;
		ropes.push_back(rope);
	}

	sort(ropes.begin(), ropes.end(), descent);

	for (int i = 0; i < N; i++) {
		int weight = ropes[i] * (i + 1);
		ans = max(ans, weight);
	}

	cout << ans << endl;

	return 0;
}
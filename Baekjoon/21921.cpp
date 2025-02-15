#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr;
	vector<int> pSum;
	int N, X;
	cin >> N >> X;

	arr.resize(N, 0);
	pSum.resize(N + 1, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		pSum[i + 1] = arr[i] + pSum[i];
	}

	int max = 0;
	for (int i = X - 1; i < N; i++) {
		int s = i - X + 1;
		int e = i;
		int sum = pSum[e + 1] - pSum[s];

		max = sum > max ? sum : max;
	}

	int cnt = 0;
	for (int i = X - 1; i < N; i++) {
		int s = i - X + 1;
		int e = i;
		int sum = pSum[e + 1] - pSum[s];

		if (sum == max)
			cnt++;
	}

	if (max == 0) {
		cout << "SAD" << endl;
	}
	else {
		cout << max << endl;
		cout << cnt << endl;
	}

	return 0;
}
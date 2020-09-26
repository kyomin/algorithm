#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int A[100000];
int pSum[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		pSum[i + 1] = A[i] + pSum[i];
	}

	vector<int> v;

	for (int start = 0; start < N; start++) {
		if (start + K > N)
			break;

		v.push_back(pSum[start + K] - pSum[start]);
	}

	cout << *max_element(v.begin(), v.end()) << '\n';

	return 0;
}
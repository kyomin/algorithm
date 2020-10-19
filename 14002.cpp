#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	int *A = new int[N + 1];
	int *DP = new int[N + 1];
	vector<int> *V = new vector<int>[N + 1];

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		A[i] = n;
	}

	V[1].push_back(A[1]);

	for (int i = 1; i <= N; i++)
		DP[i] = 1;

	for (int i = 2; i <= N; i++) {
		int index = 0;

		for (int j = 1; j < i; j++) {
			if (A[i] > A[j] && DP[j] + 1 > DP[i]) {
				DP[i] = DP[j] + 1;
				index = j;
			}
		}

		if (index != 0) {
			vector<int> v = V[index];
			v.push_back(A[i]);
			V[i] = v;
		}
		else
			V[i].push_back(A[i]);
	}

	int max = DP[1];
	int idx = 1;

	for (int i = 2; i <= N; i++) {
		if (DP[i] > max) {
			max = DP[i];
			idx = i;
		}
	}

	cout << max << '\n';

	for (int i = 0; i < V[idx].size(); i++)
		cout << V[idx][i] << ' ';

	cout << endl;

	return 0;
}
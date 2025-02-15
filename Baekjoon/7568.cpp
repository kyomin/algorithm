#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, int>> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back(make_pair(a, b));
	}

	int *A = new int[N];

	for (int i = 0; i < N; i++)
		A[i] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == i)
				continue;

			if (v[i].first < v[j].first && v[i].second < v[j].second)
				A[i] += 1;
		}
	}

	for (int i = 0; i < N; i++)
		cout << A[i] + 1 << ' ';

	cout << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> dots;
	int N, M;
	cin >> N >> M;

	dots.resize(N);
	for (int i = 0; i < N; i++)
		cin >> dots[i];

	sort(dots.begin(), dots.end());

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;

		cout << upper_bound(dots.begin(), dots.end(), end) - lower_bound(dots.begin(), dots.end(), start) << '\n';
	}

	return 0;
}
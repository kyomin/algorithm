#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<int> arr(N);

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end());

		cout << '#' << t << ' ';

		for (int i = 0; i < N; i++)
			cout << arr[i] << ' ';

		cout << endl;
	}

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long arr[100000];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	if (M == 0) {
		cout << 0 << '\n';
		return 0;
	}

	int s = 0, e = 0, cnt = 0;
	long long diff = 0;
	long long result;

	while (true) {
		if ((e == N) && (diff < M))
			break;

		if (diff < M) {
			e++;
			diff = arr[e] - arr[s];
		}
		else {
			cnt++;

			if (cnt == 1)
				result = diff;

			result = min(result, diff);

			s++;
			diff = arr[e] - arr[s];
		}
	}

	cout << result << '\n';

	return 0;
}
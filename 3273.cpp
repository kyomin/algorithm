#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int arr[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, X;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> X;

	sort(arr, arr + N);

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int low = 0;
		int high = N - 1;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (arr[mid] == X - arr[i]) {
				ans++;
				break;
			}
			else if (arr[mid] < X - arr[i])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}

	cout << ans / 2 << '\n';

	return 0;
}
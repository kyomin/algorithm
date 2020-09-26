#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<int> arr;
		arr.resize(N);

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		bool isAscend;

		int ans = 1;

		int startIdx = N;

		// 첫 부분배열이 오름차순인지 내림차순인지 판단
		for (int i = 1; i < N; i++) {
			if (arr[i] == arr[i - 1])
				continue;

			if (arr[i] > arr[i - 1]) {
				isAscend = true;
				startIdx = i + 1;
				break;
			}

			if (arr[i] < arr[i - 1]) {
				isAscend = false;
				startIdx = i + 1;
				break;
			}
		}

		for (int i = startIdx; i < N; i++) {
			// 같을 경우는 현재 오름차순이든 내림차순이든 다 적용이므로
			if (arr[i] == arr[i - 1])
				continue;

			// 현재 오름차순 진행일 경우에
			if (isAscend) {
				if (arr[i] > arr[i - 1]) {
					continue;
				}
				else {
					if (i + 1 < N) {
						if (arr[i] < arr[i + 1]) {
							ans++;
							continue;
						}
						else {
							isAscend = false;
							ans++;
							continue;
						}
					}

					isAscend = false;
					ans++;
					continue;
				}
			}
			else {	// 현재 내림차순 진행일 경우에
				if (arr[i] < arr[i - 1]) {
					continue;
				}
				else {
					if (i + 1 < N) {
						if (arr[i] > arr[i + 1]) {
							ans++;
							continue;
						}
						else {
							isAscend = true;
							ans++;
							continue;
						}
					}

					isAscend = true;
					ans++;
					continue;
				}
			}
		}

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}
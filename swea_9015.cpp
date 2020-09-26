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

		// ù �κй迭�� ������������ ������������ �Ǵ�
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
			// ���� ���� ���� ���������̵� ���������̵� �� �����̹Ƿ�
			if (arr[i] == arr[i - 1])
				continue;

			// ���� �������� ������ ��쿡
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
			else {	// ���� �������� ������ ��쿡
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
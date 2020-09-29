#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];

int main() {
	int N;
	cin >> N;

	for (int n = 0; n < N; n++)
		cin >> A[n];

	/* 감소하는 구간 먼저 구한다 */
	int decrease_ans = 0;
	int decreasing_length;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			decreasing_length = 1;
			continue;
		}

		if (A[i] <= A[i - 1]) {
			decreasing_length++;
			continue;
		}
		else {
			decrease_ans = max(decrease_ans, decreasing_length);
			decreasing_length = 1;
		}
	}

	decrease_ans = max(decrease_ans, decreasing_length);

	/* 증가하는 구간을 구한다 */
	int increase_ans = 0;
	int increasing_length;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			increasing_length = 1;
			continue;
		}

		if (A[i] >= A[i - 1]) {
			increasing_length++;
			continue;
		}
		else {
			increase_ans = max(increase_ans, increasing_length);
			increasing_length = 1;
		}
	}

	increase_ans = max(increase_ans, increasing_length);

	cout << max(decrease_ans, increase_ans) << '\n';

	return 0;
}
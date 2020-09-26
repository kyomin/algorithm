#include <iostream>

using namespace std;

int steps[100001];
int arr[100001];

int main() {
	int N;
	cin >> N;

	int step = 1, first = 1, last = N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	while (step <= N) {
		// 홀수 단계 => 작은 숫자
		if (step % 2 == 1) {
			int curIdx;		// 타겟 발견 시의 인덱스
			int cnt = 0;	// 이동 횟수를 셀 것이다.

			for (int i = 1; i <= N; i++) {
				if (arr[i] == first) {
					curIdx = i;
					break;
				}
			}

			// 안 움직여도 되는 상황
			if (first == curIdx)
				steps[step] = cnt;

			// 왼쪽으로 이동!
			for (int i = curIdx; i > first; i--) {
				// swap !!
				int temp = arr[i-1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				cnt++;
			}

			steps[step] = cnt;
			first++;
			step++;
		}
		else {		// 짝수 단계 => 큰 숫자
			int curIdx;		// 타겟 발견 시의 인덱스
			int cnt = 0;	// 이동 횟수를 셀 것이다.

			for (int i = 1; i <= N; i++) {
				if (arr[i] == last) {
					curIdx = i;
					break;
				}
			}

			// 안 움직여도 되는 상황
			if (first == curIdx)
				steps[step] = cnt;

			// 오른쪽으로 이동!
			for (int i = curIdx; i < last; i++) {
				// swap !!
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				cnt++;
			}

			steps[step] = cnt;
			last--;
			step++;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << steps[i] << '\n';
	}

	return 0;
}
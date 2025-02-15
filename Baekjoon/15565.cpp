#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> arr(N);

	int allRionCnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if (arr[i] == 1)
			allRionCnt++;
	}

	// 예외 처리
	if (allRionCnt < K) {
		cout << -1 << endl;
		return 0;
	}

	int s = 0;
	int e = 0;
	int len = N;
	int cnt = 0;
	while (true) {
		// 두 포인터 모두 끝에 도달하면
		if (s == N && e == N)
			break;

		// 목표 라이언 인형의 개수에 도달하면
		if (cnt == K) {
			int diff = e - s;
			len = min(len, diff);	// 최소 길이 갱신
		}

		if (e == N || cnt >= K) {
			if (arr[s] == 1)
				cnt -= 1;

			s++;
		} else {
			if (arr[e] == 1)
				cnt += 1;

			e++;
		}
	}

	cout << len << endl;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> A(N);
	int start = 0;
	int end = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];

		// 레슨 최댓값을 시작 인덱스로 저장
		if (start < A[i])
			start = A[i];

		// 모든 레슨의 값을 종료 인덱스로 저장
		end += A[i];
	}

	// 이분 탐색 시작
	while (start <= end) {
		int middle = (start + end) / 2;
		int sum = 0;
		int count = 0;

		// 중앙값으로 모든 레슨을 저장할 수 있는지 확인
		for (int i = 0; i < N; i++) {
			if (sum + A[i] > middle) {
				count++;
				sum = 0;
			}

			sum += A[i];
		}

		// 마지막을 위한 블루레이가 필요한 경우
		if (sum != 0)
			count++;

		// 지정된 개수로 못 담는 경우
		if (count > M)
			start = middle + 1;
		// 지정된 개수 내에서 담는 경우
		else
			end = middle - 1;
	}

	cout << start << '\n';

	return 0;
}
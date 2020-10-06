#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
	int answer = 0;
	int N = cookie.size();

	// 바로 해를 구할 수 있는 가장 작은 경우들 처리!
	if (N == 1)
		return 0;

	if (N == 2)
		if (cookie[0] == cookie[1])
			return cookie[0];
		else
			return 0;

	for (int i = 0; i < N - 1; i++) {
		int left_idx = i;
		int right_idx = i + 1;

		int left_sum = cookie[left_idx];
		int right_sum = cookie[right_idx];

		if (left_sum == right_sum)
			answer = max(answer, left_sum);

		while (true) {
			// 현재 왼쪽 구간이 작다면 왼쪽에 더해 나간다.
			if (left_sum < right_sum) {
				// 왼쪽 끝인 경우
				if (left_idx == 0)
					break;

				left_idx -= 1;
				left_sum += cookie[left_idx];
			}
			// 오른쪽에 더해주는 경우
			else if (left_sum > right_sum) {
				// 오른쪽 끝인 경우
				if (right_idx == N - 1)
					break;

				right_idx += 1;
				right_sum += cookie[right_idx];
			}
			// 같아지는 경우
			else {
				answer = max(answer, left_sum);

				if (left_idx == 0 || right_idx == N - 1)
					break;

				left_idx -= 1;
				right_idx += 1;

				left_sum += cookie[left_idx];
				right_sum += cookie[right_idx];
			}
		}
	}

	return answer;
}
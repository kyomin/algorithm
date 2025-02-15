#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	sort(times.begin(), times.end());

	long long left = 0;								// 최소 시간 1분
	long long right = times[times.size() - 1];	// 최대 시간
	right *= n;
	answer = right;		// 일단 정답은 최대 걸리는 시간으로 설정(최악)
	long long mid;

	// 왼쪽 포인터가 오른쪽을 역전하지 않을 때까지 => 이분탐색 조건
	while (left <= right) {
		long long done = 0;		// 해당 mid분일 시 검사대에서 검사할 수 있는 총 사람 수를 담는다
		mid = (left + right) / 2;

		for (auto time : times)
			done += (mid / time);

		// 검사해야 하는 사람의 수보다 적은 경우
		if (done < n)
			left = mid + 1;
		// 검사해야 하는 사람의 수보다 많은 경우
		else {
			if (mid <= answer) answer = mid;
			right = mid - 1;
		}
	}

	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	vector<int> times;
	cin >> N >> M;

	times.resize(N);

	for (int n = 0; n < N; n++)
		cin >> times[n];

	cout << solution(M, times);

	return 0;
}
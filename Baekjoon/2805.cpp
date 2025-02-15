#include <iostream>

using namespace std;

int main() {
	unsigned long long lo = 0, hi = 1000000000;
	unsigned long long N, M, height[1000000];
	cin >> N >> M;

	for (unsigned long long i = 0; i < N; i++)
		cin >> height[i];

	// 이분 탐색 시작
	while (lo + 1 < hi) {
		unsigned long long mid = (lo + hi) / 2;

		// 각 나무에 대해서 mid가 절단기 설정 높이일 때를 계산해 길이 합을 구한다.
		unsigned long long sum = 0;

		for (unsigned long long i = 0; i < N; i++)
			if (height[i] > mid)
				sum += (height[i] - mid);

		// mid로 M 이상의 길이를 가져갈 수 있는 경우
		if (sum >= M)
			lo = mid;
		else
			hi = mid;
	}

	cout << lo << endl;

	return 0;
}
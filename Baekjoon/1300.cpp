#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, K;

// mid의 인덱스를 구하는 함수
ll findIndex(ll mid) {
	ll cnt = 0;

	for (ll i = 1; i <= N; i++)
		cnt += min(N, mid / i);		// mid / i > N인 경우 처리

	return cnt;		// mid의 인덱스
}

int main() {
	cin >> N >> K;

	// 가질 수 있는 값의 범위는 1 ~ N*N
	ll left = 1;
	ll right = N * N;
	ll ans = 1;

	while (left <= right) {
		// 중앙 값으로 지정한 현재 원소
		ll mid = (left + right) / 2;

		// 현재 원소의 인덱스가 더 크다면
		if (findIndex(mid) >= K) {
			// 현재 원소를 감소시켜 확인(같은 값의 원소가 있는 것을 고려)
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}
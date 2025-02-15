#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, K;

// mid�� �ε����� ���ϴ� �Լ�
ll findIndex(ll mid) {
	ll cnt = 0;

	for (ll i = 1; i <= N; i++)
		cnt += min(N, mid / i);		// mid / i > N�� ��� ó��

	return cnt;		// mid�� �ε���
}

int main() {
	cin >> N >> K;

	// ���� �� �ִ� ���� ������ 1 ~ N*N
	ll left = 1;
	ll right = N * N;
	ll ans = 1;

	while (left <= right) {
		// �߾� ������ ������ ���� ����
		ll mid = (left + right) / 2;

		// ���� ������ �ε����� �� ũ�ٸ�
		if (findIndex(mid) >= K) {
			// ���� ���Ҹ� ���ҽ��� Ȯ��(���� ���� ���Ұ� �ִ� ���� ���)
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}
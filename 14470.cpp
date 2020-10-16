#include <iostream>

using namespace std;

int main() {
	int ans = 0;
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

	// 영하라면
	if (A < 0) {
		// 마찬가지로 목표 온도도 영하라면
		if (B <= 0) {
			int diff = B - A;
			ans += (diff*C);
		}
		// 목표 온도가 상온이라면
		else {
			// 일단 0도까지 올린다.
			ans += (((-1)*A)*C);
			A = 0;

			// 0도인 고기 해동
			ans += D;

			ans += B * E;
		}
	}
	// 상온이라면(A가 0인 경우는 입력으로 주어지지 않는다)
	else {
		ans += (B-A) * E;
	}

	cout << ans << '\n';

	return 0;
}
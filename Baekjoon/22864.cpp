#include <iostream>
using namespace std;

int main() {
	int A, B, C, M;
	cin >> A >> B >> C >> M;

	int T = 0;	// 피로도
	int W = 0;	// 작업량

	for (int i = 0; i < 24; i++) {
		// 번아웃
		if (T > M) {
			W = 0;
			break;
		}

		// 일을 할 수 있는 경우
		if (T + A <= M) {
			T += A;
			W += B;

			continue;
		}

		// 일을 할 수 없는 경우 휴식
		T = T - C >= 0 ? T - C : 0;
	}

	cout << W << endl;

	return 0;
}
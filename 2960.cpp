#include <iostream>

using namespace std;

int main() {
	int count = 0;	// 몇 번째인지를 표시하기 위한 변수
	int ans;	// 정답을 담기 위한 변수
	int N, K;
	cin >> N >> K;

	bool *C = new bool[N + 1];

	for (int i = 2; i <= N; i++)
		C[i] = false;

	for (int i = 2; i <= N; i++) {
		int judge = 0;

		for (int j = i * 1; j <= N; j += i) {
			// 아직 지워지지 않은 수라면
			if (C[j] == false) {
				C[j] = true;

				count += 1;

				if (count == K) {
					ans = j;
					judge = 1;

					break;
				}
			}
		}

		if (judge == 1)
			break;
	}

	cout << ans << endl;

	return 0;
}
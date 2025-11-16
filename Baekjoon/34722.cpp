#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int s, c, a, r;
		cin >> s >> c >> a >> r;

		if (s >= 1000) {
			cnt++;
			continue;
		}

		if (c >= 1600) {
			cnt++;
			continue;
		}

		if (a >= 1500) {
			cnt++;
			continue;
		}

		if (r != -1 && r <= 30) {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
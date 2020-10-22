#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> position;
	int N, L;
	cin >> N >> L;

	position.resize(N);

	for (int i = 0; i < N; i++)
		cin >> position[i];

	sort(position.begin(), position.end());

	int start = 0;
	int cnt = 0;

	for (auto pos : position) {
		// 테이프 붙이기 => 현 위치로부터 L-1까지는 테이프로 커버가 가능하다.
		if (start < pos) {
			start = pos + L - 1;
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
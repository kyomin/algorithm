#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> home;

int installRouter(int distance) {
	int cnt = 1;
	int cur_home = home[0];		// 공유기가 설치된 집

	for (int i = 1; i < N; i++) {
		// 공유기를 설치하고자 하는 집과의 간격(mid)이 더 크면 설치
		if (distance <= home[i] - cur_home) {
			cnt++;
			cur_home = home[i];
		}
	}

	return cnt;
}

int main() {
	cin >> N >> C;
	home.resize(N);

	for (int i = 0; i < N; i++)
		cin >> home[i];

	sort(home.begin(), home.end());

	int ans = 1;
	int start = 1;
	int end = home[N - 1] - home[0];

	// 이분 탐색 시작!
	while (start <= end) {
		int mid = (start + end) / 2;
		int router_cnt = installRouter(mid);

		// 공유기의 갯수가 모자라면, 목표 간격을 좁힌다.
		if (router_cnt < C)
			end = mid - 1;
		// 공유기를 목표치 이상으로 설치할 수 있다면 정답이 될 수 있음.
		else if (router_cnt >= C) {
			ans = mid;
			start = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
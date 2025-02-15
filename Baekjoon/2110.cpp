#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> home;

int installRouter(int distance) {
	int cnt = 1;
	int cur_home = home[0];		// �����Ⱑ ��ġ�� ��

	for (int i = 1; i < N; i++) {
		// �����⸦ ��ġ�ϰ��� �ϴ� ������ ����(mid)�� �� ũ�� ��ġ
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

	// �̺� Ž�� ����!
	while (start <= end) {
		int mid = (start + end) / 2;
		int router_cnt = installRouter(mid);

		// �������� ������ ���ڶ��, ��ǥ ������ ������.
		if (router_cnt < C)
			end = mid - 1;
		// �����⸦ ��ǥġ �̻����� ��ġ�� �� �ִٸ� ������ �� �� ����.
		else if (router_cnt >= C) {
			ans = mid;
			start = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
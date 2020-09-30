#include <iostream>

using namespace std;

int friends[1001];
int N, M, L;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> L;

	// 1번 자리에 앉은 친구가 처음 공을 받는 경우를 처리
	int ans = 0;		
	int cur_friend = 1;
	friends[cur_friend]++;

	while (true) {
		int cur_cnt = friends[cur_friend];
		if (cur_cnt == M) break;

		/*
			현재 받은 사람이 홀수번 받았을 경우 -> 시계 방향(+L)
			현재 받은 사람이 짝수번 받았을 경우 -> 반시계 방향(-L)
		*/
		cur_friend = (cur_cnt % 2 == 1) ? (cur_friend + L) : cur_friend - L;

		// 다음 받을 사람이 배열의 범위를 벗어났을 경우(시계 방향일 때)
		if (cur_friend > N)
			cur_friend %= N;
		// 다음 받을 사람이 배열의 범위를 벗어났을 경우(반시계 방향일 때)
		else if (cur_friend < 1)
			cur_friend += N;

		friends[cur_friend]++;	// 공 받는 사람 ++
		ans++;	// 공 던진 횟수 ++
	}

	cout << ans << '\n';

	return 0;
}
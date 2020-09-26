#include <iostream>
#include <vector>

using namespace std;

// first : 사람 번호, second : 공 받은 횟수 
vector<pair<int, int>> friends;
int N, M, L;
int cnt = 1;	// 횟수
int cur = 1;	// 현재 공 가지고 있는 사람

int main() {
	cin >> N >> M >> L;

	// 인덱스는 1부터 시작하기 위함이다.
	friends.resize(N + 1);

	// 처음 1번은 공을 받은 상태이다.
	friends[1] = make_pair(1, 1);

	// 나머지 친구들 입력
	for (int i = 2; i <= N; i++) {
		friends[i] = make_pair(i, 0);
	}

	while (true) {
		// M번 잡은 사람이 생기면 게임 종료!
		if (friends[cur].second == M)
			break;
		
		// 현재 잡은 횟수가 홀수이면 시계방향으로 작업
		if (friends[cur].second % 2 == 1) {
			cur = (friends[cur].first + L) % N;
			friends[cur].second += 1;
			cnt++;
		} else {	// 반시계 방향 작업
			if (cur - L <= 0) {
				cur = (cur - L) + N;
				friends[cur].second += 1;
				cnt++;
			} else {
				cur = (cur - L);
				friends[cur].second += 1;
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}
#include <iostream>

using namespace std;

int friends[1001];
int N, M, L;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> L;

	// 1�� �ڸ��� ���� ģ���� ó�� ���� �޴� ��츦 ó��
	int ans = 0;		
	int cur_friend = 1;
	friends[cur_friend]++;

	while (true) {
		int cur_cnt = friends[cur_friend];
		if (cur_cnt == M) break;

		/*
			���� ���� ����� Ȧ���� �޾��� ��� -> �ð� ����(+L)
			���� ���� ����� ¦���� �޾��� ��� -> �ݽð� ����(-L)
		*/
		cur_friend = (cur_cnt % 2 == 1) ? (cur_friend + L) : cur_friend - L;

		// ���� ���� ����� �迭�� ������ ����� ���(�ð� ������ ��)
		if (cur_friend > N)
			cur_friend %= N;
		// ���� ���� ����� �迭�� ������ ����� ���(�ݽð� ������ ��)
		else if (cur_friend < 1)
			cur_friend += N;

		friends[cur_friend]++;	// �� �޴� ��� ++
		ans++;	// �� ���� Ƚ�� ++
	}

	cout << ans << '\n';

	return 0;
}
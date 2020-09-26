#include <iostream>
#include <vector>

using namespace std;

// first : ��� ��ȣ, second : �� ���� Ƚ�� 
vector<pair<int, int>> friends;
int N, M, L;
int cnt = 1;	// Ƚ��
int cur = 1;	// ���� �� ������ �ִ� ���

int main() {
	cin >> N >> M >> L;

	// �ε����� 1���� �����ϱ� �����̴�.
	friends.resize(N + 1);

	// ó�� 1���� ���� ���� �����̴�.
	friends[1] = make_pair(1, 1);

	// ������ ģ���� �Է�
	for (int i = 2; i <= N; i++) {
		friends[i] = make_pair(i, 0);
	}

	while (true) {
		// M�� ���� ����� ����� ���� ����!
		if (friends[cur].second == M)
			break;
		
		// ���� ���� Ƚ���� Ȧ���̸� �ð�������� �۾�
		if (friends[cur].second % 2 == 1) {
			cur = (friends[cur].first + L) % N;
			friends[cur].second += 1;
			cnt++;
		} else {	// �ݽð� ���� �۾�
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
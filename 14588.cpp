#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� ���� �� ���� ��� ��
const int INF = 1000000000;

int friends[301][301];
int N;

// first : ������, second : ����
vector<pair<int, int>> lines;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			friends[y][x] = (y == x) ? 0 : INF;

	// �ε����� 1���� �����ϱ� ����
	lines.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int start, end;
		cin >> start >> end;

		lines[i] = make_pair(start, end);
	}

	// ���� ���� �Է� ����
	for (int y = 1; y <= N; y++) {
		// ���� �ľ��ϰ��� �ϴ� ģ���� ���
		int boundaryLeft = lines[y].first;
		int boundaryRight = lines[y].second;

		for (int x = 1; x <= N; x++) {
			if (y == x)
				continue;

			int start = lines[x].first;
			int end = lines[x].second;

			// ���� ģ���� ��� ���ο� �ִٸ� ģ���� �׻� 1�̴�.
			if ((start >= boundaryLeft && start <= boundaryRight) || (end >= boundaryLeft && end <= boundaryRight)
				|| (boundaryLeft >= start && boundaryLeft <= end) || (boundaryRight >= start && boundaryRight <= end)) {
				friends[y][x] = 1;
			}
		}
	}

	// �÷��̵� �ͼ� �˰��� ����
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);

	int Q;
	cin >> Q;

	for (int q = 0; q < Q; q++) {
		int A, B;
		cin >> A >> B;

		if (friends[A][B] == INF)
			cout << -1 << '\n';
		else
			cout << friends[A][B] << '\n';
	}

	return 0;
}
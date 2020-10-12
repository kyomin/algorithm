#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;	// �ִ� ��ǥ �� ����
bool visited[MAX];	// ��ǥ �湮 ���� üũ

int BFS(int N, int K) {
	for (int i = 0; i < MAX; i++)
		visited[i] = false;

	// first : ��ǥ, second : �ð�
	queue<pair<int, int>> q;

	q.push(make_pair(N, 0));

	visited[N] = true;

	while (!q.empty()) {
		int n = q.front().first;
		int curSec = q.front().second;

		q.pop();

		/*
			��ǥ ��ǥ�� ���������� �Լ� ����!
			�� ���� ����ؼ� ť�� �������� �׾�
			���� ���� ��ǥ ��ǥ�� �����ϴ� ���� ��
			�ּ� �ð��� �����ϴ� ���̴�.
		*/
		if (n == K)
			return curSec;

		/*
			�� ���� ����� ��
			�湮�� ���� ť�� ���� �ʴ´�
		*/
		if (n - 1 >= 0 && visited[n - 1] == false) {
			q.push(make_pair(n - 1, curSec + 1));
			visited[n - 1] = true;
		}

		if (n + 1 < MAX && visited[n + 1] == false) {
			q.push(make_pair(n + 1, curSec + 1));
			visited[n + 1] = true;
		}

		if (n * 2 < MAX && visited[n * 2] == false) {
			q.push(make_pair(n * 2, curSec + 1));
			visited[n * 2] = true;
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	cout << BFS(N, K) << endl;

	return 0;
}
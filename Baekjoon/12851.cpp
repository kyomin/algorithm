#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;

int cnt;
int minSec;
bool visited[MAX];

int minSecond(int N, int K) {
	queue<pair<int, int>> q;

	q.push(make_pair(N, 0));

	visited[N] = true;

	while (!q.empty()) {
		int curLoc = q.front().first;
		int curSec = q.front().second;

		q.pop();

		//���ٲ����� �޸� ���ٲ��� 2������ ť���� pop�� �� �湮���� ǥ��
		visited[curLoc] = true; 

		//�̹� �������� �ѹ� �������� ��� cnt++
		if (minSec != 0 && minSec == curSec && curLoc == K)
			cnt++;

		//���ʷ� ������ ���޽� �ּ� �ð� ����ϰ� cnt++
		if (minSec == 0 && curLoc == K) {
			minSec = curSec;

			cnt++;
		}

		//�� ���� ����� ��

		if (curLoc + 1 < MAX && !visited[curLoc + 1])
			q.push(make_pair(curLoc + 1, curSec + 1));

		if (curLoc - 1 >= 0 && !visited[curLoc - 1])
			q.push(make_pair(curLoc - 1, curSec + 1));

		if (curLoc * 2 < MAX && !visited[curLoc * 2])
			q.push(make_pair(curLoc * 2, curSec + 1));
	}

	return minSec;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	minSecond(N, K);

	cout << minSec << "\n";
	cout << cnt << endl;

	return 0;
}
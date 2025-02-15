#include <iostream>
#include <algorithm>

using namespace std;

int N, S[100000], cnt;
bool visited[100000];
bool finished[100000];

void DFS(int curr) {
	// �湮 �ߴ�!
	visited[curr] = true;

	// ���� �湮 ���� ���
	int next = S[curr];

	// ���� ������ �̹� �湮�Ǿ� �ְ�
	if (visited[next]) {
		// ���� �Լ� ���ᰡ �� �Ǿ��ٸ�
		if (!finished[next]) {
			for (int temp = next; temp != curr; temp = S[temp])
				cnt++;

			// �ڱ� �ڽ�
			cnt++;
		}
	}
	else // ���� ������ ���� �湮�� ���� �ƴ϶��
		DFS(next);

	// ���� Ž���� ��ġ�� ��Ͱ� ������ �ڱ� �Լ��� ���ƿ�
	finished[curr] = true;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &S[i]);
			// �ε��� �����ֱ�
			S[i]--;
		}

		// �� ������Ʈ�� ���� DFS ����!
		fill(visited, visited + N, false);
		fill(finished, finished + N, false);

		cnt = 0;

		for (int i = 0; i < N; i++)
			if (!visited[i])
				DFS(i);
			
		// ����Ŭ�� ������ ���� ���� ���!
		printf("%d\n", N - cnt);
	}

	return 0;
}
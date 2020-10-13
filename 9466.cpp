#include <iostream>
#include <algorithm>

using namespace std;

int N, S[100000], cnt;
bool visited[100000];
bool finished[100000];

void DFS(int curr) {
	// 방문 했다!
	visited[curr] = true;

	// 다음 방문 정점 담기
	int next = S[curr];

	// 다음 정점이 이미 방문되어 있고
	if (visited[next]) {
		// 아직 함수 종료가 안 되었다면
		if (!finished[next]) {
			for (int temp = next; temp != curr; temp = S[temp])
				cnt++;

			// 자기 자신
			cnt++;
		}
	}
	else // 다음 정점이 아직 방문된 것이 아니라면
		DFS(next);

	// 깊이 탐색을 마치면 재귀가 끝나고 자기 함수로 돌아옴
	finished[curr] = true;
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &S[i]);
			// 인덱스 맞춰주기
			S[i]--;
		}

		// 각 컴포넌트에 대해 DFS 시작!
		fill(visited, visited + N, false);
		fill(finished, finished + N, false);

		cnt = 0;

		for (int i = 0; i < N; i++)
			if (!visited[i])
				DFS(i);
			
		// 싸이클에 속하지 않은 것을 출력!
		printf("%d\n", N - cnt);
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int N;
vector<int> vc;	// 출력할 것 담기
bool visit[10];	// 숫자가 쓰이는지 확인

void DFS() {
	if (vc.size() == N) {
		for (auto i : vc)
			printf("%d ", i);

		printf("\n");

		return;
	}

	for (int i = 1; i <= N; i++) {
		// vc에 담기지 않았다면
		if (!visit[i]) {
			// 담았다 check!
			visit[i] = true;

			// vc에 추가!
			vc.push_back(i);

			// 재귀 호출!
			DFS();

			// vc에서 빼주기
			vc.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%d", &N);

	DFS();

	return 0;
}
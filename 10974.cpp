#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int N;
vector<int> vc;	// ����� �� ���
bool visit[10];	// ���ڰ� ���̴��� Ȯ��

void DFS() {
	if (vc.size() == N) {
		for (auto i : vc)
			printf("%d ", i);

		printf("\n");

		return;
	}

	for (int i = 1; i <= N; i++) {
		// vc�� ����� �ʾҴٸ�
		if (!visit[i]) {
			// ��Ҵ� check!
			visit[i] = true;

			// vc�� �߰�!
			vc.push_back(i);

			// ��� ȣ��!
			DFS();

			// vc���� ���ֱ�
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
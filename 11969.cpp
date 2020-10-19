#include <cstdio>

using namespace std;

int N, Q;
int breed1[1000001] = { 0, };
int breed2[1000001] = { 0, };
int breed3[1000001] = { 0, };

int main() {
	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; i++) {
		int A;
		scanf("%d", &A);

		if (A == 1) {
			breed1[i + 1] = breed1[i] + 1;
			breed2[i + 1] = breed2[i];
			breed3[i + 1] = breed3[i];
		}
		else if (A == 2) {
			breed1[i + 1] = breed1[i];
			breed3[i + 1] = breed3[i];
			breed2[i + 1] = breed2[i] + 1;
		}
		else {
			breed1[i + 1] = breed1[i];
			breed2[i + 1] = breed2[i];
			breed3[i + 1] = breed3[i] + 1;
		}
	}

	for (int i = 0; i < Q; i++) {
		int s, e;

		scanf("%d %d", &s, &e);

		printf("%d %d %d\n",
			breed1[e + 1] - breed1[s],
			breed2[e + 1] - breed2[s],
			breed3[e + 1] - breed3[s]
		);
	}

	return 0;
}
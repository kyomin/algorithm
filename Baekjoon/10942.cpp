#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 2000;

int N, M;
int arr[MAX + 1];

// 메모제이션을 위한 배열
bool cache[MAX + 1][MAX + 1];

void palindrome() {
	// 길이 1
	for (int i = 1; i <= N; i++)
		cache[i][i] = true;

	// 길이 2
	for (int i = 1; i < N; i++)
		if (arr[i] == arr[i + 1])
			cache[i][i + 1] = true;

	// 길이 3 이상
	for (int i = 2; i < N; i++)
		for (int j = 1; j <= N - i; j++)
			// 앞 뒤가 같고, 그 가운데 수들이 팰린드롬인 경우
			if (arr[j] == arr[j + i] && cache[j + 1][j + i - 1])
				cache[j][j + i] = true;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	cin >> M;

	memset(cache, false, sizeof(cache));

	palindrome();

	for (int i = 0; i < M; i++) {
		int S, E;

		scanf("%d %d", &S, &E);

		printf("%d\n", cache[S][E]);
	}

	return 0;
}
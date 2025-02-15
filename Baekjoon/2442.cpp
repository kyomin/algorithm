#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	// 가장 마지막 줄의 별의 갯수
	int max = (2 * N) - 1;

	for (int i = 1; i <= N; i++) {
		// 현재 행의 별의 갯수
		int num_of_star = (i * 2) - 1;

		// 별이 찍히기 시작하는 인덱스
		int start = (max - num_of_star) / 2;

		// 별찍기가 끝나는 인덱스
		int end = start + (num_of_star - 1);

		for (int j = 0; j <= end; j++) {
			if (j >= start && j <= end)
				cout << '*';
			else
				cout << ' ';
		}

		// 행이 끝나면 개행을 시켜준다.
		cout << '\n';
	}

	return 0;
}
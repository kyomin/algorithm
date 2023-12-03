#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> a(N, 0), b(N);

	for (auto& i : b)
		cin >> i;

	// B -> A
	int cnt = 0;
	while (true) {
		int zeroCount = 0;

		// 1 감소 횟수 구하기
		for (auto& i : b) {
			if (i % 2) {
				cnt++;
				i--;
			}

			if (i == 0)
				zeroCount++;
		}

		// A 배열(모든 원소가 0인 배열)에 도달한 경우
		if (zeroCount == N)
			break;

		// 2 나눈 횟수 구하기
		cnt++;

		for (auto& i : b)
			i /= 2;
	}

	cout << cnt << endl;

	return 0;
}
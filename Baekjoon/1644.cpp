#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int N;
	cin >> N;

	bool *C = new bool[N + 1];

	for (int i = 2; i <= N; i++)
		C[i] = false;

	for (int i = 2; i <= N; i++) {
		if (C[i] == false) {
			// 소수 담기!
			v.push_back(i);

			for (int j = i * 2; j <= N; j += i)
				C[j] = true;
		}
	}

	/*
	 위의 에라토스테네스의 체 알고리즘을 빠져나오면
	 벡터 v에 N이하의 소수들이 담긴다.
	 */

	// 투 포인터 알고리즘을 위한 변수들 선언!
	int len = v.size();
	int s = 0, e = 0;
	int sum = 0;
	int count = 0;

	// 포인터가 배열 인덱스 끝까지 가기 전까지
	while (e < len || s < len) {
		if (sum < N) {
			if (e == len)
				break;

			sum += v[e];

			e += 1;

			if (sum == N)
				count++;
		}
		else {
			sum -= v[s];
			s += 1;

			if (sum == N)
				count++;
		}
	}

	cout << count << endl;

	return 0;
}
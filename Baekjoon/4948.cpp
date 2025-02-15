#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> len;

	while (true) {
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		vector<int> p;	// 소수 저장용 벡터
		int N;
		cin >> N;

		// 입력이 0이라면 반복문 탈출!
		if (N == 0)
			break;

		// true : 지워짐, false : 아직 지워지지 않음
		bool *c = new bool[2 * N + 1];

		for (int i = 0; i <= 2 * N; i++)
			c[i] = false;

		// 가장 작은 소수 2부터 시작한다.
		for (int i = 2; i <= 2 * N; i++) {
			// 아직 지워지지 않았다면
			if (c[i] == false) {
				// 범위 내에 있다면
				if (i > N)
					// 소수에 추가시키고
					p.push_back(i);

				// 배수만큼 돌면서
				for (int j = i * 2; j <= 2 * N; j += i)
					// 지워준다.
					c[j] = true;
			}
		}

		// 소수 벡터에 추가된 사이즈를 담고서
		len.push_back(p.size());
	}

	int length = len.size();

	for (int i = 0; i < length; i++)
		cout << len[i] << '\n';

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> p;	// 소수 저장용 벡터
	int M, N;
	cin >> M >> N;

	// true : 지워짐, false : 아직 지워지지 않음
	bool *c = new bool[N + 1];

	for (int i = 0; i <= N; i++)
		c[i] = false;

	// 가장 작은 소수 2부터 시작한다.
	for (int i = 2; i <= N; i++) {
		// 아직 지워지지 않았다면
		if (c[i] == false) {
			// 범위 내에 있다면
			if (i >= M)
				// 소수에 추가시키고
				p.push_back(i);

			// 배수만큼 돌면서
			for (int j = i * 2; j <= N; j += i)
				// 지워준다.
				c[j] = true;
		}
	}

	// 소수 벡터에 추가된 사이즈를 담고서
	int len = p.size();

	// for문을 돌리면서 출력!
	for (int i = 0; i < len; i++)
		cout << p[i] << '\n';

	return 0;
}
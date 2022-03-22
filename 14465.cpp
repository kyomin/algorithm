#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K, B;
	cin >> N >> K >> B;
	vector<bool> arr(N, false);	// true --> ���峭 ��ȣ��

	for (int i = 0; i < B; i++) {
		int idx;
		cin >> idx;

		arr[idx - 1] = true;
	}

	int s = 0;
	int e = 0;
	int len = 0;
	int cnt = 0;
	int ans = N;
	while (true) {
		// �� ������ ��� ���� �����ϸ�
		if (s == N && e == N)
			break;

		if (len == K) {
			ans = min(ans, cnt);
		}

		if (e == N || len >= K) {
			if (arr[s])
				cnt--;

			s++;
			len--;
		}
		else {
			if (arr[e])
				cnt++;

			e++;
			len++;
		}
	}

	cout << ans << endl;

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int mid = M / 2;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		int cnt = 0;
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) {
			char ch = str[j];

			if (ch == 'O')
				cnt++;
		}

		if (cnt > mid)
			ans++;
	}

	cout << ans << endl;

	return 0;
}
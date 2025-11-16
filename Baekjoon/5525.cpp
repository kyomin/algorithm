#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	string str;
	cin >> str;

	int i = 0;
	int ans = 0;
	int cnt = 0;

	while (i < M - 2) {
		if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') {
			cnt++;

			if (cnt >= N) {
				ans++;
			}

			i += 2;
		}
		else {
			cnt = 0;
			i += 1;
		}
	}

	cout << ans << endl;

	return 0;
}
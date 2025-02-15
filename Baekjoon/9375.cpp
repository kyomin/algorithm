#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		map<string, int> m;
		int N;
		cin >> N;

		for (int n = 0; n < N; n++) {
			string cloth, kind;
			cin >> cloth >> kind;
			
			if (m.find(kind) == m.end())
				m[kind] = 1;
			else
				m.find(kind)->second += 1;
		}

		int ans = 1;

		for (auto it = m.begin(); it != m.end(); it++)
			ans *= (it->second+1);

		ans -= 1;

		cout << ans << '\n';
	}

	return 0;
}
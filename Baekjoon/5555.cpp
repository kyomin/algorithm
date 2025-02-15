#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string target;
	int N;
	int ans = 0;

	cin >> target >> N;

	int target_len = target.size();

	for (int n = 0; n < N; n++) {
		string ring;
		cin >> ring;

		int len = ring.size();
		bool found = false;

		ring += ring;

		for (int i = 0; i < len; i++) {
			string str = ring.substr(i, target_len);

			if (str == target) {
				found = true;
				break;
			}
		}

		if (found)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}
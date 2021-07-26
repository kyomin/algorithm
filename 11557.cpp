#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		string univ_ans = "";
		int most_consumption = 0;

		for (int n = 0; n < N; n++) {
			string univ;
			int consumption;

			cin >> univ >> consumption;

			if (consumption > most_consumption) {
				univ_ans = univ;
				most_consumption = consumption;
			}
		}

		cout << univ_ans << '\n';
	}

	return 0;
}
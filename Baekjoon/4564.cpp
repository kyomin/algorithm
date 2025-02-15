#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		string N;
		cin >> N;

		if (N == "0")
			break;

		while (N.size() > 1) {
			cout << N << ' ';

			int len = N.size();
			int newNum = 1;

			for (int i = 0; i < len; i++)
				newNum *= (int)(N[i] - '0');

			N = to_string(newNum);
		}

		cout << N << '\n';
	}

	return 0;
}
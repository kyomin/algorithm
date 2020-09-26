#include <iostream>
#include <stack>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		
		stack<int> s;

		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;

			if (n != 0) {
				s.push(n);
			}
			else {
				s.pop();
			}
		}

		int sum = 0;

		while (!s.empty()) {
			sum += s.top();
			s.pop();
		}

		cout << '#' << t << ' ' << sum << '\n';
	}

	return 0;
}
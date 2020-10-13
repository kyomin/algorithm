#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	while (true) {
		vector<int> v;
		int judge = 0;

		while (true) {
			int n;
			cin >> n;

			if (n == -1) {
				judge = -1;
				break;
			}

			if (n == 0)
				break;

			v.push_back(n);
		}

		if (judge == -1)
			break;

		sort(v.begin(), v.end());

		int len = v.size();
		int cnt = 0;

		for (int i = 0; i < len; i++) {
			int a = v[i] * 2;

			for (int j = i + 1; j < len; j++) {
				if (a == v[j]) {
					cnt++;
					break;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}
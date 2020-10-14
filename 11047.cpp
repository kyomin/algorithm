#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		v.push_back(n);
	}

	int len = v.size();
	int count = 0;

	for (int i = len - 1; i >= 0; i--) {
		if (K == 0)
			break;

		int num = K / v[i];
		count += num;
		K -= (num*v[i]);
	}

	cout << count << '\n';

	return 0;
}
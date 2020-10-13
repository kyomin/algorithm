#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int H, W, N;
		cin >> H >> W >> N;

		int a = N / H;
		int b = N % H;

		if (b == 0) {
			b = H;
			a -= 1;
		}

		b *= 100;
		v.push_back((b + a + 1));
	}

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << '\n';

	return 0;
}
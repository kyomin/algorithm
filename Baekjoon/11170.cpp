#include <iostream>
#include <string>

using namespace std;

int countZero(string num) {
	int len = num.length();
	int ret = 0;

	for (int i = 0; i < len; i++)
		if (num[i] == '0')
			ret++;

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T; 

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		int num_of_zero = 0;
		for (int n = N; n <= M; n++)
			num_of_zero += countZero(to_string(n));

		cout << num_of_zero << '\n';
	}

	return 0;
}
#include <iostream>

using namespace std;

bool PC[101];

int main() {
	int result = 0;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (!PC[n])
			PC[n] = true;
		else
			result++;
	}

	cout << result << '\n';

	return 0;
}
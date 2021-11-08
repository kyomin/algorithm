#include <iostream>

using namespace std;

int main() {
	int result = 0;
	int A, B, C;
	int N;
	cin >> A >> B >> C;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			sum += (a*A + b * B + c * C);
		}

		if (sum > result)
			result = sum;
	}

	cout << result << endl;

	return 0;
}
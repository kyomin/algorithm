#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int C, K;
	cin >> C >> K;

	if (K == 0) {
		cout << C << endl;
		return 0;
	}

	int num = pow(10, K);
	int standard = num / 2;
	int q = C / num;
	int r = C % num;

	int result = q * num;

	if (r >= standard)
		result += num;

	cout << result << endl;

	return 0;
}
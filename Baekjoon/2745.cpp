#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string N;
	int B;
	unsigned long result = 0;

	cin >> N >> B;

	int len = N.size();

	for (int i = 0; i < len; i++) {
		int n;
		int x = len - i - 1;

		// '0' ~ '9'¶ó¸é
		if (N[i] >= 48 && N[i] <= 57) {
			n = (unsigned long)(N[i] - '0');
			result += n * (unsigned long)pow(B, x);
		}
		else {
			n = (unsigned long)(10 + (N[i] - 'A'));
			result += n * (unsigned long)pow(B, x);
		}
	}

	cout << result << endl;

	return 0;
}
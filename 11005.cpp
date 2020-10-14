#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string result = "";
	unsigned long N;
	int B;
	cin >> N >> B;

	while (N >= B) {
		long r = N % B;
		N /= B;

		if (r < 10)
			result += (char)(r + '0');
		else if (r >= 10)
			result += (char)((r - 10) + 'A');
	}

	if (N < 10)
		result += (char)(N + '0');
	else if (N >= 10)
		result += (char)((N - 10) + 'A');

	// string 변수 뒤집기!
	reverse(result.begin(), result.end());

	cout << result << endl;

	return 0;
}
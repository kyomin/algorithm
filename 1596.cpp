#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 10^x를 구한다.
int pow10(int x) {
	if (x == 0)
		return 1;

	return 10 * pow10(x - 1);
}

int solution(string num) {
	int len = num.size();

	// 한자리 수라면
	if (len == 1)
		return atoi(num.c_str());

	int result = 0;

	for (int i = 1; i < len; i++) {
		int diff;
		int n1 = (int)(num[i] - '0');
		int n2 = (int)(num[i-1] - '0');

		diff = abs(n1 - n2);

		result += (diff*pow10(len - i - 1));
	}

	return solution(to_string(result));
}

int main() {
	int A, B;
	cin >> A >> B;

	int ans = 0;

	for (int i = A; i <= B; i++) {
		int result = solution(to_string(i));

		if (result == 7)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}
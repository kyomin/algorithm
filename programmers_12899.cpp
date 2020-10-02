#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
	string answer = "";

	int digits[4] = { 4, 1, 2, 4 };

	while (n > 3) {
		int r = n % 3;

		n /= 3;

		if (r == 0)
			n -= 1;

		answer += to_string(digits[r]);
	}

	answer += to_string(digits[n]);

	reverse(answer.begin(), answer.end());

	return answer;
}
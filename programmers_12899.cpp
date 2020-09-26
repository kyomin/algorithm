#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n) {
	string answer = "";

	int digits[4] = { 4, 1, 2, 4 };

	while (n > 3)
	{
		int r = n % 3;

		n /= 3;

		if (r == 0)
		{
			n -= 1;
		}

		answer += to_string(digits[r]);
	}

	answer += to_string(digits[n]);

	reverse(answer.begin(), answer.end());

	return answer;
}

int main()
{
	for (int i = 1; i < 12; i++)
	{
		cout << solution(i) << '\n';
	}

	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string S;
	cin >> S;

	int len = S.length();
	int zero_area = 0;
	int one_area = 0;
	char cur_char = S[0];

	if (cur_char == '0')
		zero_area++;
	else
		one_area++;

	for (int i = 1; i < len; i++) {
		if (S[i] == cur_char)
			continue;

		if (S[i] == '0')
			zero_area++;
		else
			one_area++;

		cur_char = S[i];
	}

	cout << min(zero_area, one_area) << endl;

	return 0;
}
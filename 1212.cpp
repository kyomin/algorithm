#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string BIN(char c) {
	int N = (int)(c - '0');
	string result = "000";
	int i = 2;
	
	while (N >= 2) {
		unsigned long r = N % 2;
		N = N / 2;

		result[i] = (char)(r + '0');

		i--;
	}

	result[i] = (char)(N + '0');

	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string result = "";
	string s;
	cin >> s;

	int len = s.size();

	for (int i = 0; i < len; i++)
		result += BIN(s[i]);

	len = result.size();

	if (result.substr(0, 2) == "00" && result != "000")
		cout << result.substr(2, len) << endl;
	else if (result[0] == '0' && result != "000")
		cout << result.substr(1, len) << endl;
	else if (result == "000")
		cout << "0" << endl;
	else
		cout << result << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

char BtoD(string str) {
	int len = str.size();
	int sum = 0;

	for (int i = 0; i < len; i++) {
		int x = len - i - 1;
		int n = (int)(str[i] - '0');
		sum += n * (int)pow(2, x);
	}

	sum = (char)(sum + '0');

	return sum;
}

int main() {
	string s;
	string result = "";

	cin >> s;

	int len = s.size();

	if (len % 3 == 2)
		s = "0" + s;
	else if (len % 3 == 1)
		s = "00" + s;

	len = s.size() / 3;

	for (int i = 0; i < len; i++) {
		char c = BtoD(s.substr(i * 3, 3));
		result += c;
	}

	cout << result << endl;

	return 0;
}
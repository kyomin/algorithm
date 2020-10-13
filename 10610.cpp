#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool com(char c1, char c2) {
	if (c1 > c2)
		return true;
	else
		return false;
}

int main() {
	string str;
	string zero = "";
	string num = "";

	cin >> str;

	int len = str.size();
	int count = 0;
	int sum = 0;

	for (int i = 0; i < len; i++) {
		if (str[i] == '0') {
			zero += str[i];
			count++;
		}
		else {
			num += str[i];
			sum += (int)(str[i] - '0');
		}
	}

	if ((count == 0) || (sum % 3 != 0)) {
		cout << -1 << endl;
		return 0;
	}

	vector<char> v;

	len = num.size();

	for (int i = 0; i < len; i++)
		v.push_back(num[i]);

	sort(v.begin(), v.end(), com);

	string result = "";

	for (int i = 0; i < len; i++)
		result += v[i];

	result += zero;

	cout << result << endl;

	return 0;
}
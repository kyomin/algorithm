#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int pow26(int x) {
	if (x == 0)
		return 1;

	return 26 * pow26(x - 1);
}

int calcDigit26(string str) {
	int len = str.size();
	int ret = 0;

	for (int i = 0; i < len; i++)
		ret += ((int)(str[i] - 'A')*pow26(len - i - 1));

	return ret;
}

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string number;
		cin >> number;

		vector<string> v = split(number, '-');

		int first = calcDigit26(v[0]);
		int second = atoi(v[1].c_str());

		if (abs(first - second) <= 100)
			cout << "nice" << '\n';
		else
			cout << "not nice" << '\n';
	}

	return 0;
}
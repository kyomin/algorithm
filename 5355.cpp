#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

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
	// 빠른 입출력
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 소수 둘째 자리까지
	cout.setf(ios::fixed);
	cout.precision(2);

	int T;
	cin >> T;

	cin.get();
	for (int t = 0; t < T; t++) {
		string cpps;
		getline(cin, cpps);

		vector<string> strs = split(cpps, ' ');
		float num = atof(strs[0].c_str());

		for (int i = 1; i < strs.size(); i++) {
			string str = strs[i];

			if (str == "@")
				num *= 3;
			else if (str == "%")
				num += 5;
			else
				num -= 7;
		}

		cout << num << '\n';
	}

	return 0;
}
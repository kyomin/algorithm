#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<string> v;
	string temp = "";
	string str;
	getline(cin, str);

	cin.ignore();

	int len = str.size();

	for (int i = 0; i < len - 1; i++) {
		if (str[i] == ' ' || str[i] == ',')
			continue;

		temp += str[i];

		if (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == ';') {
			v.push_back(temp);
			temp = "";
		}
	}

	// 첫 번째에 담긴 것이 명령어이다.
	string command = v[0];

	// 결과를 담을 것이다.
	vector<string> result;

	len = v.size();
	temp = "";

	for (int i = 1; i < len; i++) {
		string s = v[i];
		string var = "";
		int l = s.size();

		for (int j = l - 1; j >= 0; j--) {
			if (s[j] == '[')
				temp += ']';
			else if (s[j] == ']')
				temp += '[';
			else if (s[j] == '&' || s[j] == '*')
				temp += s[j];
			else
				var += s[j];
		}

		reverse(var.begin(), var.end());

		result.push_back(
			command + temp + " " + var + ';'
		);

		temp = "";
	}

	len = result.size();

	for (int i = 0; i < len; i++)
		cout << result[i] << '\n';

	return 0;
}
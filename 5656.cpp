#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SPLIT(vector<string>& v, string str, char token) {
	int start = 0;
	int len = str.size();

	for (int i = 0; i < len; i++) {
		// ���� ���ڿ��� ó������ ��ū ���ڸ� ������ �ƹ��͵� ���� �ʴ´�. 
		if (i == 0 && str[i] == token) {
			start = i + 1;
			continue;
		}

		// ���ڿ��� ���̶��
		if (i == len - 1)
			v.push_back(str.substr(start, i + 1));
		else if (str[i] == token) {
			v.push_back(str.substr(start, i - start));
			start = i + 1;
		}
	}
}

int main() {
	vector<string> v;
	int count = 1;

	while (true) {
		int n1, n2;
		string str;
		string s = "Case " + to_string(count) + ": ";
		getline(cin, str);

		SPLIT(v, str, ' ');

		if (v[1] == "E")
			break;
		else if (v[1] == ">") {
			n1 = atoi(v[0].c_str());
			n2 = atoi(v[2].c_str());

			if (n1 > n2) {
				s += "true";
				cout << s << '\n';
			}
			else {
				s += "false";
				cout << s << '\n';
			}
		}
		else if (v[1] == ">=") {
			n1 = atoi(v[0].c_str());
			n2 = atoi(v[2].c_str());

			if (n1 >= n2) {
				s += "true";
				cout << s << '\n';
			}
			else {
				s += "false";
				cout << s << '\n';
			}
		}
		else if (v[1] == "<") {
			n1 = atoi(v[0].c_str());
			n2 = atoi(v[2].c_str());

			if (n1 < n2) {
				s += "true";
				cout << s << '\n';
			}
			else {
				s += "false";
				cout << s << '\n';
			}
		}
		else if (v[1] == "<=") {
			n1 = atoi(v[0].c_str());
			n2 = atoi(v[2].c_str());

			if (n1 <= n2) {
				s += "true";
				cout << s << '\n';
			}
			else {
				s += "false";
				cout << s << '\n';
			}
		}
		else if (v[1] == "==") {
			n1 = atoi(v[0].c_str());
			n2 = atoi(v[2].c_str());

			if (n1 == n2) {
				s += "true";
				cout << s << '\n';
			}
			else {
				s += "false";
				cout << s << '\n';
			}
		}
		else if (v[1] == "!=") {
			n1 = atoi(v[0].c_str());
			n2 = atoi(v[2].c_str());

			if (n1 != n2) {
				s += "true";
				cout << s << '\n';
			}
			else {
				s += "false";
				cout << s << '\n';
			}
		}

		v.clear();
		count++;
	}

	return 0;
}
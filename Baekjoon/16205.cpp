#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string answer[3];
int num;
string str;

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
	cin >> num >> str;

	answer[num - 1] = str;

	int len = str.size();

	if (num == 1) {
		string case2 = "";
		string case3 = str;

		// 앞 글자만 대문자로 변경
		case3[0] = (char)(str[0] - 32);

		for (int i = 0; i < len; i++) {
			// 대문자를 만난다면
			if (isupper(str[i])) {
				case2 += '_';
				case2 += (char)(str[i] + 32);
			}
			else
				case2 += str[i];
		}

		answer[1] = case2;
		answer[2] = case3;
	}
	else if (num == 2) {
		vector<string> v = split(str, '_');

		string case1 = "";
		string case3 = "";

		// 카멜 표기법 구하기!
		for (int i = 0; i < v.size(); i++) {
			if (i == 0) {
				case1 += v[i];
				continue;
			}

			string temp = v[i];

			temp[0] = (char)(v[i][0] - 32);

			case1 += temp;
		}

		// 파스칼 표기법 구하기!
		for (int i = 0; i < v.size(); i++) {
			string temp = v[i];
			temp[0] = (char)(v[i][0] - 32);

			case3 += temp;
		}

		answer[0] = case1;
		answer[2] = case3;
	}
	else {
		string case1 = str;
		string case2 = "";

		case1[0] = (char)(str[0] + 32);

		for (int i = 0; i < len; i++) {
			if (i == 0) {
				case2 += (char)(str[i] + 32);
				continue;
			}

			// 대문자를 만난다면
			if (isupper(str[i])) {
				case2 += '_';
				case2 += (char)(str[i] + 32);
			}
			else
				case2 += str[i];
		}

		answer[0] = case1;
		answer[1] = case2;
	}

	for (int i = 0; i < 3; i++)
		cout << answer[i] << '\n';

	return 0;
}
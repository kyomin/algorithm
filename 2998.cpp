#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, string> m;
	string str;
	cin >> str;

	m["000"] = "0";
	m["001"] = "1";
	m["010"] = "2";
	m["011"] = "3";
	m["100"] = "4";
	m["101"] = "5";
	m["110"] = "6";
	m["111"] = "7";

	while (str.size() % 3 != 0)
		str = "0" + str;

	string ans = "";

	int size = str.size();

	for (int i = 0; i < size; i += 3) {
		string temp = "";

		for (int j = i; j < i + 3; j++)
			temp += str[j];

		ans += m.find(temp)->second;
	}

	cout << ans << '\n';

	return 0;
}
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int len = str.length();
	set<string> s;

	for (int subLen = 1; subLen <= len; subLen++) {
		for (int i = 0; i <= (len - subLen); i++) {
			s.insert(str.substr(i, subLen));
		}
	}

	cout << s.size() << endl;

	return 0;
}
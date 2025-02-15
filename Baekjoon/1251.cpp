#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	set<string> s;

	int len = str.size();

	for (int cur1 = 1; cur1 < (len - 1); cur1++) {
		for (int cur2 = (cur1 + 1); cur2 < len; cur2++) {
			string s1 = str.substr(0, cur1);
			string s2 = str.substr(cur1, cur2 - cur1);
			string s3 = str.substr(cur2, len - cur2);

			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());

			string result = s1 + s2 + s3;

			s.insert(result);
		}
	}

	set<string>::iterator iter = s.begin();

	cout << *iter << '\n';

	return 0;
}
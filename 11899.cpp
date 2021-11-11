#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int ans = 0;
	int len;
	stack<char> s;
	string str;
	cin >> str;

	len = str.length();

	for (int i = 0; i < len; i++) {
		char ch = str[i];

		if (ch == '(') {
			s.push(ch);
		}
		else {
			if (s.size() == 0)
				ans++;
			else
				s.pop();
		}
	}

	ans += s.size();

	cout << ans << endl;
}
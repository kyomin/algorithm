#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int  t = 1;

	while (true) {
		int cnt = 0;
		string str;
		cin >> str;

		if (str[0] == '-')
			break;

		vector<char> stack;
		int len = str.size();

		for (int i = 0; i < len; i++) {
			if (stack.empty() && str[i] == '}') {
				str[i] = '{';
				cnt++;
				stack.push_back(str[i]);
			}
			else if (!stack.empty() && str[i] == '}')
				stack.pop_back();
			else
				stack.push_back(str[i]);
		}

		cnt += stack.size() / 2;

		printf("%d. %d\n", t, cnt);

		t++;
	}

	return 0;
}
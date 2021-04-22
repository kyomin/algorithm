#include <string>

using namespace std;

class Solution {
public:
	string interpret(string command) {
		int len = command.length();
		int i = 0;
		string ans = "";

		while (i < len) {
			if (command[i] == '(') {
				if (command[i + 1] == ')') {
					ans += 'o';
					i += 2;
					continue;
				}
				else {
					ans += "al";
					i += 4;
					continue;
				}
			}
			else {
				ans += 'G';
				i += 1;
			}
		}

		return ans;
	}
};
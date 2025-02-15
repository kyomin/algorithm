#include <iostream>
#include <string>

using namespace std;

int main() {
	string result = "";
	string s;
	cin >> s;

	int len = s.length();

	for (int i = 0; i < len; i++)
		result += (char)(s[i] - 32);
	
	cout << result << '\n';

	return 0;
}
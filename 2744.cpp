#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int len = str.size();

	for (int i = 0; i < len; i++) {
		if (isupper(str[i]))
			str[i] = (char)(str[i] + 32);
		else
			str[i] = (char)(str[i] - 32);		
	}

	cout << str << '\n';

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int len = str.size();
	int result = 10;

	for (int i = 1; i < len; i++) {
		// ���� �������� ������ ���
		if (str[i] == str[i - 1])
			result += 5;
		else
			result += 10;
	}

	cout << result << '\n';

	return 0;
}
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string str;
	cin >> str;

	int len = str.size();
	unsigned long result = 0;

	for (int i = 0; i < len; i++) {
		// ���� ���ڶ��
		if (str[i] >= 48 && str[i] <= 57) {
			int x = (int)(str[i] - '0');
			int a = (len - i - 1);

			result += x * (int)pow(16, a);
		}
		else {
			int x = (10 + (int)(str[i] - 'A'));
			int a = (len - i - 1);

			result += x * (int)pow(16, a);
		}
	}

	cout << result << endl;

	return 0;
}
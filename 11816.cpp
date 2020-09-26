#include <iostream>
#include <string>

using namespace std;

int powOfOct(int x) {
	if (x == 0)
		return 1;

	return 8 * powOfOct(x - 1);
}

int powOfHex(int x) {
	if (x == 0)
		return 1;

	return 16 * powOfHex(x - 1);
}

int octToDecimal(string num) {
	int len = num.size();
	int sum = 0;

	for (int i = 0; i < len; i++) {
		int n = (int)(num[i] - '0');
		n *= powOfOct(len - 1 - i);
		sum += n;
	}

	return sum;
}

int hexToDecimal(string num) {
	int len = num.size();
	int sum = 0;

	for (int i = 0; i < len; i++) {
		if (isdigit(num[i])) {
			int n = (int)(num[i] - '0');
			n *= powOfHex(len - 1 - i);
			sum += n;
		}
		else {
			int n = 10;
			n += (int)(num[i] - 'a');
			n *= powOfHex(len - 1 - i);
			sum += n;
		}
	}

	return sum;
}

int main() {
	string num;
	cin >> num;

	// 10진수인 경우 바로 출력
	if (num[0] != '0') {
		cout << num << '\n';
		return 0;
	}

	// 8진수인 경우
	if (num.substr(0, 2) != "0x") {
		cout << octToDecimal(num.substr(1, num.size())) << '\n';
	}
	else {
		cout << hexToDecimal(num.substr(2, num.size())) << '\n';
	}

	return 0;
}
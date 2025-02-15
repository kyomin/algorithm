#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string result = "";
	string str1, str2;
	cin >> str1 >> str2;

	// ĳ���� ���� ����!
	int carry = 0;
	int len1 = str1.size();
	int len2 = str2.size();

	if (len1 > len2) {
		// ���ڿ� ������ ���̸� ���Ѵ�.
		int dif = len1 - len2;

		for (int i = len2 - 1; i >= 0; i--) {
			int n1 = (int)(str1[i + dif] - '0');
			int n2 = (int)(str2[i] - '0');

			if ((n1 + n2 + carry) == 0) {
				result += '0';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 1) {
				result += '1';
				carry = 0;
			}
			// ���⼭���� ĳ���� ����� �����̴�.
			else if ((n1 + n2 + carry) == 2) {
				result += '0';
				carry = 1;
			} 
			else if ((n1 + n2 + carry) == 3) {
				result += '1';
				carry = 1;
			}
		}

		// �� ���� �����ִ� �κ��� ó���Ѵ�.
		string remains = str1.substr(0, dif);

		for (int i = dif - 1; i >= 0; i--) {
			int n = (int)(remains[i] - '0');

			if (n + carry == 0) {
				result += '0';
				carry = 0;
			}
			else if (n + carry == 1) {
				result += '1';
				carry = 0;
			}
			else if (n + carry == 2) {
				result += '0';
				carry = 1;
			}
		}

		// �۾��� �� ���ƴµ��� ĳ���� �ϳ� �ִٸ�
		if (carry == 1)
			result += '1';
	}
	else if (len1 < len2) {
		int dif = len2 - len1;

		for (int i = len1 - 1; i >= 0; i--) {
			int n1 = (int)(str2[i + dif] - '0');
			int n2 = (int)(str1[i] - '0');

			if ((n1 + n2 + carry) == 0) {
				result += '0';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 1) {
				result += '1';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 2) {
				result += '0';
				carry = 1;
			}
			else if ((n1 + n2 + carry) == 3) {
				result += '1';
				carry = 1;
			}
		}

		string remains = str2.substr(0, dif);

		for (int i = dif - 1; i >= 0; i--) {
			int n = (int)(remains[i] - '0');

			if (n + carry == 0) {
				result += '0';
				carry = 0;
			}
			else if (n + carry == 1) {
				result += '1';
				carry = 0;
			}
			else if (n + carry == 2) {
				result += '0';
				carry = 1;
			}
		}

		// �۾��� �� ���ƴµ��� ĳ���� �ϳ� �ִٸ�
		if (carry == 1)
			result += '1';
	}
	else {
		for (int i = len1 - 1; i >= 0; i--) {
			int n1 = (int)(str2[i] - '0');
			int n2 = (int)(str1[i] - '0');

			if ((n1 + n2 + carry) == 0) {
				result += '0';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 1) {
				result += '1';
				carry = 0;
			}
			else if ((n1 + n2 + carry) == 2) {
				result += '0';
				carry = 1;
			}
			else if ((n1 + n2 + carry) == 3) {
				result += '1';
				carry = 1;
			}
		}

		if (carry == 1)
			result += '1';
	}

	// �ڿ������� ���� ���̹Ƿ� ��������� ����� �� ����� ���´�.
	reverse(result.begin(), result.end());

	// result ���ڿ��� 1�� ���������� �Ǵܿ� ����
	int judge = 0;
	int length = result.size();

	// ���� ���� ��� ���� �����̴�.
	string final;

	// result �տ� 0�� �پ������� �װ��� �����ϴ� �����̴�.
	for (int i = 0; i < length; i++) {
		// 1�� ������ ����
		if (result[i] == '1') {
			// �� �������� ������ ���ڿ��� �߶󳽴�.
			final = result.substr(i, length);
			// �Ǵܿ� ������ �ϳ� ������Ų��.
			judge++;

			// �ݺ��� Ż��!
			break;
		}
	}

	// ���� ���� �ݺ����� �� ���Ҵµ��� judge�� 0�̶�� ����� �� 0�̶� �Ҹ��̹Ƿ�
	if (judge == 0)
		final = "0";

	cout << final << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <cctype> // isupper�� ���ؼ�

using namespace std;

int main() {
	string result = "";	// ��� ���ڿ��� ��� ���� ����
	string str;
	getline(cin, str);

	int len = str.size();

	for (int i = 0; i < len; i++) {
		// �빮���� ���!
		if (isupper(str[i])) {
			// �ƽ�Ű ���� ���� ��´�.
			int temp = (int)str[i];

			// 13��ŭ �о��.
			temp += 13;

			// 'Z'�� �Ѿ��
			if (temp > 90) {
				// �ƽ�Ű ��(����)������ ���� �ٽ� ����ȭ �Ѵ�.
				char c = char((temp % 91) + 65);
				result += c;
			}
			else
				result += (char)temp;
		}
		// �ҹ����� ���
		else if (islower(str[i])) {
			// �ƽ�Ű ���� ���� ��´�.
			int temp = (int)str[i];

			// 13��ŭ �о��.
			temp += 13;

			// 'Z'�� �Ѿ��
			if (temp > 122) {
				char c = char((temp % 123) + 97);
				result += c;
			}
			else
				result += (char)temp;
		}
		// ������ �����ٸ�
		else
			result += str[i];
	}

	cout << result << endl;

	return 0;
}
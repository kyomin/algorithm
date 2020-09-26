#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	string temp = "";
	string result = "";
	
	bool isInTag = false;

	int len = str.size();

	for (int i = 0; i < len; i++) {
		// ���� �±׸� �����ٸ�
		if (str[i] == '<') {
			reverse(temp.begin(), temp.end());
			result += temp;
			temp.clear();
			isInTag = true;
			temp += str[i];
			continue;
		}

		// �ݴ� �±׸� �����ٸ�
		if (str[i] == '>') {
			isInTag = false;
			temp += str[i];
			result += temp;
			temp.clear();
			continue;
		}

		// ������ �����ٸ�
		if (str[i] == ' ') {
			// ���� �±� �����
			if (isInTag) {
				temp += str[i];
				continue;
			}
			else {
				reverse(temp.begin(), temp.end());
				temp += str[i];

				result += temp;
				temp.clear();
				continue;
			}
		}

		// �׳� ���ڶ��
		temp += str[i];
	}

	reverse(temp.begin(), temp.end());
	result += temp;

	cout << result << '\n';

	return 0;
}
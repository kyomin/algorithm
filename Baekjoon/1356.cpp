#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	// ������ �Ǵ� ����!
	int judge = 0;
	int len = str.size();

	if (len == 1) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < len - 1; i++) {
		// �־��� ���ڿ��� �� �������� �ɰ� ���̴�.
		string s1 = str.substr(0, i + 1);
		string s2 = str.substr(i + 1, len - (i + 1));

		int n1 = 1;
		int n2 = 1;

		int len1 = s1.size();
		int len2 = s2.size();

		// �������� ���ڿ��� ���Ͽ� ������ �ǽ��Ѵ�.
		for (int i = 0; i < len1; i++)
			n1 *= (int)(s1[i] - '0');

		for (int i = 0; i < len2; i++)
			n2 *= (int)(s2[i] - '0');

		// ���� ���� �κ��� ���ܹ����� �Ǵ� ���� ����!
		if (n1 == n2)
			judge++;
	}

	if (judge > 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	string str1, str2;
	cin >> str1 >> str2;

	// ������ �̸��� �ٿ��� �����ϱ� ���� ����
	string result = "";

	int len = str1.size();

	for (int i = 0; i < len; i++) {
		result += str1[i];
		result += str2[i];
	}

	len = result.size();

	for (int i = 0; i < len; i++) {
		int n = (int)(result[i] - '0');
		v.push_back(n);
	}

	// ���������� ���س����� ���꿡���� �������� 2���� �����Ƿ� ���̰� 2�� �ƴ� ������!
	while (len != 2) {
		// ���ϴ� �۾��� ���ش�.
		for (int i = 0; i < len - 1; i++) {
			v[i] += v[i + 1];

			if (v[i] >= 10)
				v[i] %= 10;
		}

		// ó�� ���̸� ���� ���� ���ҽ�Ű��!
		len--;
	}

	// ���������� v[0]�� v[1]�� ����. �̶�, 10���� ũ�ų� ������!
	if (v[0] >= 10)
		v[0] %= 10;

	cout << v[0] << v[1] << '\n';

	return 0;
}
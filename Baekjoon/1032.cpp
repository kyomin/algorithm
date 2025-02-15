#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string result = "";
	vector<string> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	// ���� �̸��� ���̴� ��� ���ٴ� �����̹Ƿ�
	int len = v[0].size();

	// ���� �̸� �ϳ��� �Է��� ���
	if (N == 1) {
		cout << v[0] << endl;
		return 0;
	}

	// �� �ڸ����� ���ڸ� ���ϸ�
	for (int i = 0; i < len; i++) {
		char c = v[0][i];

		// ���� ���� ������ �� ���̴�.
		int count = 0;

		for (int j = 1; j < N; j++)
			if (c == v[j][i])
				count++;

		// �ش� �ڸ����� ��� ���ڰ� ��ġ�ϸ�
		if (count == (N - 1))
			result += c;

		else
			result += '?';
	}

	cout << result << endl;

	return 0;
}
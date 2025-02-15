#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// ���ĺ� ������ ȹ�� Ƚ�� ����!
	int A[26] = {
		3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1
	};

	vector<int> v;
	string str1, str2;

	// �̸� �Է�!
	cin >> str1 >> str2;

	// ������ �̸��� �ٿ��� �����ϱ� ���� ����
	string result = "";

	int len1 = str1.size();
	int len2 = str2.size();

	// ���� �� ��° �̸��� ��ٸ�
	if (len1 < len2) {
		// �ϴ� ª�� �ʱ��� ���� �Ŀ�
		for (int i = 0; i < len1; i++) {
			result += str1[i];
			result += str2[i];
		}

		// ������ �� �κ��� ���̱�!
		for (int i = len1; i < len2; i++)
			result += str2[i];
	}
	// ���� �ݴ��� �۾�!
	else {
		for (int i = 0; i < len2; i++) {
			result += str1[i];
			result += str2[i];
		}

		for (int i = len2; i < len1; i++)
			result += str1[i];
	}

	// ���������� ������ ���� �̸��� ���� ����
	int len = result.size();

	// ���Ϳ��ٰ� ���������� ������ ���ڿ��� �� ���ĺ��� ����ġ ����!
	for (int i = 0; i < len; i++) {
		int n = (int)(result[i] - 65);
		v.push_back(A[n]);
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
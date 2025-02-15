#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// ���ĺ� ������ ȹ�� Ƚ�� ����!
	int A[26] = {
		3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2,
		1, 2, 1, 1, 1, 2, 2, 1
	};

	vector<int> v;
	int N, M;
	cin >> N >> M;

	string str1, str2;
	cin >> str1 >> str2;

	// ������ �̸��� �ٿ��� �����ϱ� ���� ����
	string result = "";

	// ���� �� ��° �̸��� ��ٸ�
	if (N < M) {
		// �ϴ� ª�� �ʱ��� ���� �Ŀ�
		for (int i = 0; i < N; i++) {
			result += str1[i];
			result += str2[i];
		}

		// ������ �� �κ��� ���̱�!
		for (int i = N; i < M; i++)
			result += str2[i];
	}
	// ���� �ݴ��� �۾�!
	else {
		for (int i = 0; i < M; i++) {
			result += str1[i];
			result += str2[i];
		}

		for (int i = M; i < N; i++)
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

	if (v[0] != 0)
		cout << v[0] << v[1] << '%' << '\n';
	else
		cout << v[1] << '%' << '\n';

	return 0;
}
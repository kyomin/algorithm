#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> len;

	while (true) {
		cin.tie(NULL);
		ios::sync_with_stdio(false);

		vector<int> p;	// �Ҽ� ����� ����
		int N;
		cin >> N;

		// �Է��� 0�̶�� �ݺ��� Ż��!
		if (N == 0)
			break;

		// true : ������, false : ���� �������� ����
		bool *c = new bool[2 * N + 1];

		for (int i = 0; i <= 2 * N; i++)
			c[i] = false;

		// ���� ���� �Ҽ� 2���� �����Ѵ�.
		for (int i = 2; i <= 2 * N; i++) {
			// ���� �������� �ʾҴٸ�
			if (c[i] == false) {
				// ���� ���� �ִٸ�
				if (i > N)
					// �Ҽ��� �߰���Ű��
					p.push_back(i);

				// �����ŭ ���鼭
				for (int j = i * 2; j <= 2 * N; j += i)
					// �����ش�.
					c[j] = true;
			}
		}

		// �Ҽ� ���Ϳ� �߰��� ����� ���
		len.push_back(p.size());
	}

	int length = len.size();

	for (int i = 0; i < length; i++)
		cout << len[i] << '\n';

	return 0;
}
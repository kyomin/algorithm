#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> p;	// �Ҽ� ����� ����
	int M, N;
	cin >> M >> N;

	// true : ������, false : ���� �������� ����
	bool *c = new bool[N + 1];

	for (int i = 0; i <= N; i++)
		c[i] = false;

	// ���� ���� �Ҽ� 2���� �����Ѵ�.
	for (int i = 2; i <= N; i++) {
		// ���� �������� �ʾҴٸ�
		if (c[i] == false) {
			// ���� ���� �ִٸ�
			if (i >= M)
				// �Ҽ��� �߰���Ű��
				p.push_back(i);

			// �����ŭ ���鼭
			for (int j = i * 2; j <= N; j += i)
				// �����ش�.
				c[j] = true;
		}
	}

	// �Ҽ� ���Ϳ� �߰��� ����� ���
	int len = p.size();

	// for���� �����鼭 ���!
	for (int i = 0; i < len; i++)
		cout << p[i] << '\n';

	return 0;
}
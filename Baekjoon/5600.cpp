#include <iostream>
#include <cstring>

using namespace std;

int componenets[301];
int query[1000][4];		// �˻� ��� ����

void init(int len) {
	for (int i = 1; i <= len; i++)
		componenets[i] = 2;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	// ��ü ��ǰ�� ����
	int len = a + b + c;

	init(len);

	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int i, j, k, r;
		cin >> i >> j >> k >> r;

		// r�� 1�� ��쿡�� ��ΰ� �����̹Ƿ�
		if (r == 1) {
			componenets[i] = 1;
			componenets[j] = 1;
			componenets[k] = 1;
		}

		// �ϴ� �˻� �� ����
		query[n][0] = i;
		query[n][1] = j;
		query[n][2] = k;
		query[n][3] = r;
	}

	for (int n = 0; n < N; n++) {
		// �̹� �Ǵ��� ���̹Ƿ�
		if (query[n][3] == 1)
			continue;

		// ����� ���հ��̶��
		int i, j, k;
		i = query[n][0];
		j = query[n][1];
		k = query[n][2];

		// Ȯ���ϰ� �ϳ��� �ҷ��̶�� ���� �� �ִ� ��Ȳ������
		if (componenets[i] == 1 && componenets[j] == 1)
			componenets[k] = 0;
		else if (componenets[i] == 1 && componenets[k] == 1)
			componenets[j] = 0;
		else if (componenets[j] == 1 && componenets[k] == 1)
			componenets[i] = 0;
	}

	for (int i = 1; i <= len; i++)
		cout << componenets[i] << '\n';

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

// ������ �ڷ��� ����
typedef struct Data {
	// W : ����, S : ��
	char T;

	// ���� ��
	long long Cnt;
}Data;

vector<int> vt[123458];
Data arr[123458];
int N;

long long dfs(int idx) {
	long long sum = 0;

	for (int i = 0; i < vt[idx].size(); i++)
		// �ڱ�� ����� ������ ���� ó��
		sum += dfs(vt[idx][i]);

	// �ڱ� ������ ���� ó��
	if (arr[idx].T == 'S') // ���̶��
		return arr[idx].Cnt + sum;
	else
		return (sum - arr[idx].Cnt >= 0) ? sum - arr[idx].Cnt : 0;
}

int main() {
	char a;
	int b, c;

	cin >> N;

	arr[1].T = 'S';
	arr[1].Cnt = 0;

	for (int i = 2; i <= N; i++) {
		cin >> a >> b >> c;

		vt[c].push_back(i);

		arr[i].T = a;
		arr[i].Cnt = b;
	}

	cout << dfs(1) << '\n';

	return 0;
}
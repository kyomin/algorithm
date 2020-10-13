#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int result;	// ����� ��� ���� ����
vector<int> v;	// ī����� ��� ����

// params : �ε���, ������� ������ ī�� ����, �� ��
void sumOfCards(int idx, int cnt, int sum) {
	// ������ ������ ���
	if (cnt == 3 && sum <= M) {
		// ���� result�� ��� ���� �� �� ū ���� ���
		result = max(result, sum);
		return;
	}

	// ���� ���(Ż�� ���)
	if (idx >= N || cnt > 3 || sum > M)
		return;

	// �ش� ī�带 ����
	sumOfCards(idx + 1, cnt + 1, sum + v[idx]);

	// �ش� ī�� ���� X
	sumOfCards(idx + 1, cnt, sum);
}

int main() {
	result = 0;
	cin >> N >> M;

	// ī�� ���
	v.resize(N);	// ���� ũ�� ����
	for (int i = 0; i < N; i++)
		cin >> v[i];

	// ���Ʈ ���� ����!
	sumOfCards(0, 0, 0);

	cout << result << '\n';

	return 0;
}
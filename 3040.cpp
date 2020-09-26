#include <iostream>
#include <vector>

using namespace std;

int dwarfs[9];	// �����̵�
vector<int> answer;
int sum = 0;
bool found = false;

// ���� ���ϱ�
void dfs(int cnt) {
	// 7���� ���̸�
	if (answer.size() == 7) {
		// ���� 100���� �˻� �� ���
		if (sum == 100) {
			for (auto i : answer) {
				printf("%d\n", i);
			}

			found = true;

			return;
		}

		// ���� 100�� �ƴ϶�� �׳� ����
		return;
	}

	for (int i = cnt; i < 9; i++) {
		if (answer.size() < 7) {
			answer.push_back(dwarfs[i]);
			sum += dwarfs[i];

			dfs(i + 1);

			if (found)
				return;

			answer.pop_back();
			sum -= dwarfs[i];
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> dwarfs[i];
	}

	dfs(0);

	return 0;
}
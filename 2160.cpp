#include <iostream>
#include <vector>

using namespace std;

char pictures[50][5][7];

// �ϴ� ��ΰ� �� �ٸ� ���
int minDiff = 35;
int N;

pair<int, int> ans;

vector<int> vc;

// 2���� �׸� ��!
void comp(int one, int two) {
	int diff = 0;	// �� ���� ���̰� �ִ��� ����.

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 7; col++) {
			if (pictures[one][row][col] != pictures[two][row][col]) {
				diff++;
			}
		}
	}

	if (minDiff >= diff) {
		minDiff = diff;

		// �׸� ��ȣ = �ε��� + 1
		ans.first = one+1;
		ans.second = two+1;
	}
}

void dfs(int cnt) {
	// 2���� �׸��� ���̸�
	if (vc.size() == 2) {
		comp(vc[0], vc[1]);

		return;
	}

	for (int i = cnt; i < N; i++) {
		if (vc.size() < 2) {
			vc.push_back(i);

			dfs(i + 1);

			vc.pop_back();
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int row = 0; row < 5; row++) {
			for (int col = 0; col < 7; col++) {
				cin >> pictures[i][row][col];
			}
		}
	}

	dfs(0);

	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}
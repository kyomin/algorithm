#include <iostream>
#include <vector>

using namespace std;

char pictures[50][5][7];

// 일단 모두가 다 다른 경우
int minDiff = 35;
int N;

pair<int, int> ans;

vector<int> vc;

// 2개의 그림 비교!
void comp(int one, int two) {
	int diff = 0;	// 몇 개의 차이가 있는지 센다.

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 7; col++) {
			if (pictures[one][row][col] != pictures[two][row][col]) {
				diff++;
			}
		}
	}

	if (minDiff >= diff) {
		minDiff = diff;

		// 그림 번호 = 인덱스 + 1
		ans.first = one+1;
		ans.second = two+1;
	}
}

void dfs(int cnt) {
	// 2개의 그림이 모이면
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
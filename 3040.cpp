#include <iostream>
#include <vector>

using namespace std;

int dwarfs[9];	// 난쟁이들
vector<int> answer;
int sum = 0;
bool found = false;

// 조합 구하기
void dfs(int cnt) {
	// 7명이 모이면
	if (answer.size() == 7) {
		// 합이 100인지 검사 후 출력
		if (sum == 100) {
			for (auto i : answer) {
				printf("%d\n", i);
			}

			found = true;

			return;
		}

		// 합이 100이 아니라면 그냥 종료
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
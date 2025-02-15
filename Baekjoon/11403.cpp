#include <iostream>
#include <vector>

using namespace std;

vector<int> a[100];
int ans[100][100];
bool check[100];

void dfs(int x) {
	check[x] = true;

	for (int i = 0; i < a[x].size(); i++){
		int y = a[x][i];

		if (check[y] == false)
			dfs(y);
	}
}

int main() {
	int N;
	cin >> N;

	// 인접 리스트 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;

			if (num == 1)
				a[i].push_back(j);
		}
	}

	// 해를 구한다
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			check[j] = false;

		for (int j = 0; j < a[i].size(); j++) {
			int x = a[i][j];

			if (check[x] == false)
				dfs(x);
		}

		for (int j = 0; j < N; j++) {
			if (check[j])
				ans[i][j] = 1;
			else
				ans[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << ans[i][j] << ' ';

		cout << '\n';
	}

	return 0;
}
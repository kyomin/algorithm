#include <iostream>
#include <vector>

using namespace std;

// 정점의 자료형 정의
typedef struct Data {
	// W : 늑대, S : 양
	char T;

	// 마리 수
	long long Cnt;
}Data;

vector<int> vt[123458];
Data arr[123458];
int N;

long long dfs(int idx) {
	long long sum = 0;

	for (int i = 0; i < vt[idx].size(); i++)
		// 자기와 연결된 정점에 대해 처리
		sum += dfs(vt[idx][i]);

	// 자기 정점에 대해 처리
	if (arr[idx].T == 'S') // 양이라면
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
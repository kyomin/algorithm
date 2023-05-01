#include <iostream>
using namespace std;

int arr[102][102];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	int ans = 0;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N + 2; i++)
		for (int j = 0; j < M + 2; j++)
			arr[i][j] = 0;
		
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
		
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];

				if (arr[r][c] >= arr[nr][nc])
					ans += arr[r][c] - arr[nr][nc];				
			}
		}
	}

	ans += 2 * (N*M);
	cout << ans;

	return 0;
}
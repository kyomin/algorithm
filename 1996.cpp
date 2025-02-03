#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

const int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
const int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

bool isInside(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N)
		return false;

	return true;
}

int main() {
	cin >> N;

	vector<string> map(N);
	vector<vector<char>> ans(N, vector<char>(N, '*'));

	for (int i = 0; i < N; i++)
		cin >> map[i];
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			char cur = map[r][c];

			// ���ڶ��
			if (cur != '.')
				continue;

			int sum = 0;

			// ���� 8ĭ Ž��
			for (int k = 0; k < 8; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];

				// ������ ����ٸ�
				if (!isInside(nr, nc))
					continue;

				char adjacent = map[nr][nc];

				// ���ڰ� �ƴ϶��
				if (adjacent == '.')
					continue;

				sum += (adjacent - '0');
			}

			if (sum >= 10)
				ans[r][c] = 'M';
			else
				ans[r][c] = sum + '0';
		}
	}

	// ���
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << ans[r][c];
		}

		cout << endl;
	}

	return 0;
}
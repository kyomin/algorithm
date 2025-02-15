#include <iostream>
#include <cstring>

using namespace std;

int map[100][100];
bool check[100][100];

int main() {
	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	int cnt = 0;

	// 1. ���� ���� ���� ����
	for (int r = 0; r < N; r++) {
		bool judge = true;

		for (int c = 0; c < N - 1; c++) {
			if (map[r][c] == map[r][c + 1]) continue;

			// ���� ��ġ�� 1 ���̷� �۴ٸ�
			if (map[r][c] - 1 == map[r][c + 1]) {
				// L=1�̾ �ٷ� ���θ� ���� �� �ִ� ���
				if (L == 1) {
					if(!check[r][c + 1])
						check[r][c + 1] = true;
					else {
						judge = false;
						break;
					}
				}
				else {
					// ���θ� ���������� ���� �� ���� ������ �Ÿ��� ����ϴٸ�
					if (c + L < N) {
						for (int start = c + 1; start < (c + L); start++) {
							// �̹� ���� ���̶��
							if (check[r][start] || check[r][start + 1]) {
								judge = false;
								break;
							}

							if (map[r][start] == map[r][start + 1]) continue;
							else {
								judge = false;
								break;
							}
						}

						if (!judge) break;
						else {
							for (int start = c + 1; start <= (c + L); start++)
								check[r][start] = true;
						}
					}
					else {
						judge = false;
						break;
					}
				}
			}
			// ���� ��ġ�� 1 ���̷� ũ�ٸ�
			else if (map[r][c] + 1 == map[r][c + 1]) {
				if (L == 1) {
					if (!check[r][c])
						check[r][c] = true;
					else {
						judge = false;
						break;
					}
				}
				else {
					// ���θ� �������� ���� �� ���� ������ �Ÿ��� ����ϴٸ�
					if ((c + 1 - L) >= 0) {
						for (int start = c; start > (c + 1 - L); start--) {
							// �̹� ���� ���̶��
							if (check[r][start] || check[r][start - 1]) {
								judge = false;
								break;
							}

							if (map[r][start] == map[r][start - 1]) continue;
							else {
								judge = false;
								break;
							}
						}

						if (!judge) break;
						else {
							for (int start = c; start >= (c + 1 - L); start--)
								check[r][start] = true;
						}
					}
					else {
						judge = false;
						break;
					}
				}
			}
			// ���� ��ġ�� 1 ���̷� ������, ũ���� ���� ��Ȳ�̶� ���θ� ���� �� ����
			else {
				judge = false;
				break;
			}
		}

		if (judge) cnt++;
	}

	// 2. ���� ���� ���� ����
	memset(check, false, sizeof(check));

	for (int c = 0; c < N; c++) {
		bool judge = true;

		for (int r = 0; r < N - 1; r++) {
			if (map[r][c] == map[r + 1][c]) continue;

			// ���� ��ġ�� 1 ���̷� �۴ٸ�
			if (map[r][c] - 1 == map[r + 1][c]) {
				if (L == 1) {
					if (!check[r + 1][c])
						check[r + 1][c] = true;
					else {
						judge = false;
						break;
					}
				}
				else {
					// ���θ� ���������� ���� �� ���� ������ �Ÿ��� ����ϴٸ�
					if (r + L < N) {
						for (int start = r + 1; start < (r + L); start++) {
							// �̹� ���� ���̶��
							if (check[start][c] || check[start + 1][c]) {
								judge = false;
								break;
							}

							if (map[start][c] == map[start + 1][c]) continue;
							else {
								judge = false;
								break;
							}
						}

						if (!judge) break;
						else {
							for (int start = r + 1; start <= (r + L); start++)
								check[start][c] = true;
						}
					}
					else {
						judge = false;
						break;
					}
				}
			}
			// ���� ��ġ�� 1 ���̷� ũ�ٸ�
			else if (map[r][c] + 1 == map[r + 1][c]) {
				if (L == 1) {
					if (!check[r][c])
						check[r][c] = true;
					else {
						judge = false;
						break;
					}
				}
				else {
					// ���θ� �������� ���� �� ���� ������ �Ÿ��� ����ϴٸ�
					if ((r + 1 - L) >= 0) {
						for (int start = r; start > (r + 1 - L); start--) {
							// �̹� ���� ���̶��
							if (check[start][c] || check[start - 1][c]) {
								judge = false;
								break;
							}

							if (map[start][c] == map[start - 1][c]) continue;
							else {
								judge = false;
								break;
							}
						}

						if (!judge) break;
						else {
							for (int start = r; start >= (r + 1 - L); start--)
								check[start][c] = true;
						}
					}
					else {
						judge = false;
						break;
					}
				}
			}
			// ���� ��ġ�� 1 ���̷� ������, ũ���� ���� ��Ȳ�̶� ���θ� ���� �� ����
			else {
				judge = false;
				break;
			}
		}

		if (judge) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
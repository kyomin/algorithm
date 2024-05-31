#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool pillar[102][102];
bool bar[102][102];

bool checkPillar(int x, int y) {
	// �ٴڸ� || ��� ���� ���
	if (y == 0 || pillar[x][y - 1])
		return true;

	// �� ���� ���
	if ((x > 0 && bar[x - 1][y]) || bar[x][y])
		return true;

	return false;
}

bool checkBar(int x, int y) {
	// ��� ���� ��ġ�Ǵ� ���
	if (pillar[x][y - 1] || pillar[x + 1][y - 1])
		return true;

	// ���ʿ� ���� �ִ� ���
	if (x > 0 && bar[x - 1][y] && bar[x + 1][y])
		return true;

	return false;
}

bool canDelete(int x, int y) {
	for (int i = max(x - 1, 0); i <= x + 1; i++) {
		for (int j = y; j <= y + 1; j++) {
			if (pillar[i][j] && !checkPillar(i, j))
				return false;

			if (bar[i][j] && !checkBar(i, j))
				return false;
		}
	}

	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	memset(pillar, 0, sizeof(pillar));
	memset(bar, 0, sizeof(bar));

	for (auto build : build_frame) {
		int x = build[0];
		int y = build[1];
		int type = build[2];
		int cmd = build[3];

		// ����� ���
		if (type == 0) {
			// ��ġ�� ���
			if (cmd == 1) {
				if (checkPillar(x, y))
					pillar[x][y] = true;
			}
			// ������ ���
			else {
				pillar[x][y] = false;

				// ���� �������� �ʴٸ� ����
				if (!canDelete(x, y))
					pillar[x][y] = true;
			}
		}
		// ���� ���
		else {
			// ��ġ�� ���
			if (cmd == 1) {
				if (checkBar(x, y))
					bar[x][y] = true;
			}
			// ������ ���
			else {
				bar[x][y] = false;

				// ���� �������� �ʴٸ� ����
				if (!canDelete(x, y))
					bar[x][y] = true;
			}
		}
	}

	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n; y++) {
			if (pillar[x][y])
				answer.push_back({ x, y, 0 });

			if (bar[x][y])
				answer.push_back({ x, y, 1 });
		}
	}

	return answer;
}
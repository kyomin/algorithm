#include <iostream>
#include <vector>
using namespace std;

const int MAX = 6;

int N;
bool res;
char map[MAX][MAX];
char copiedMap[MAX][MAX];
vector<pair<int, int>> coordinates;
vector<vector<pair<int, int>>> possibleCoordinates;
vector<pair<int, int>> vc;

void combinate(int cnt) {
	if (vc.size() == 3) {
		vector<pair<int, int>> copyVc = vc;
		possibleCoordinates.push_back(copyVc);

		return;
	}

	for (int i = cnt; i < coordinates.size(); i++) {
		if (vc.size() < 3) {
			vc.push_back(coordinates[i]);
			combinate(i + 1);
			vc.pop_back();
		}
	}
}

bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

void copyMap() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			copiedMap[r][c] = map[r][c];
}

void watch(int r, int c) {
	bool flag = true;
	int copyR, copyC;

	// 위로 탐색
	copyR = r - 1;
	copyC = c;
	while (isInside(copyR, copyC)) {
		if (copiedMap[copyR][copyC] == 'S') {
			flag = false;
			break;
		}

		if (copiedMap[copyR][copyC] == 'O') {
			break;
		}

		copyR--;
	}

	// 오른쪽 탐색
	copyR = r;
	copyC = c + 1;
	while (isInside(copyR, copyC)) {
		if (copiedMap[copyR][copyC] == 'S') {
			flag = false;
			break;
		}

		if (copiedMap[copyR][copyC] == 'O') {
			break;
		}

		copyC++;
	}

	// 아래 탐색
	copyR = r + 1;
	copyC = c;
	while (isInside(copyR, copyC)) {
		if (copiedMap[copyR][copyC] == 'S') {
			flag = false;
			break;
		}

		if (copiedMap[copyR][copyC] == 'O') {
			break;
		}

		copyR++;
	}

	// 왼쪽 탐색
	copyR = r;
	copyC = c - 1;
	while (isInside(copyR, copyC)) {
		if (copiedMap[copyR][copyC] == 'S') {
			flag = false;
			break;
		}

		if (copiedMap[copyR][copyC] == 'O') {
			break;
		}

		copyC--;
	}

	if (!flag) {
		res = false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> map[r][c];

	// 빈 칸의 좌표들 담기
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			if (map[r][c] == 'X')
				coordinates.push_back(make_pair(r, c));

	// 장애물을 놓을 수 있는 가능한 조합 만들기
	combinate(0);

	for (int i = 0; i < possibleCoordinates.size(); i++) {
		if (res)
			break;

		res = true;
		copyMap();
		vector<pair<int, int>> possibleCoordinate = possibleCoordinates[i];

		// 장애물 놓기
		for (int j = 0; j < possibleCoordinate.size(); j++) {
			int r = possibleCoordinate[j].first;
			int c = possibleCoordinate[j].second;

			copiedMap[r][c] = 'O';
		}

		// 선생님이면 감시 시작
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				if (copiedMap[r][c] == 'T')
					watch(r, c);
	}

	if (res)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
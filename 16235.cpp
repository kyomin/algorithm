#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeInfo {
	bool isAlive;
	int age;
};

const int MAX = 11;		// 인덱스는 1부터 시작하기 위함
int N, M, K;
int foods[MAX][MAX];	// 양분 정보
int A[MAX][MAX];
vector<TreeInfo> trees[MAX][MAX];
vector<TreeInfo> temp[MAX][MAX];

const int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void copyTreesToTemp() {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			temp[r][c] = trees[r][c];
}

void copyTempToTrees() {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			trees[r][c] = temp[r][c];
}

void input() {
	cin >> N >> M >> K;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> A[r][c];
			foods[r][c] = 5;	// 초기 양분은 5
		}
	}

	for (int m = 0; m < M; m++) {
		int x, y, z;
		cin >> x >> y >> z;

		TreeInfo treeInfo = { true, z };
		trees[x][y].push_back(treeInfo);
	}
}

bool isInside(int r, int c) {
	if (1 <= r && r <= N && 1 <= c && c <= N)
		return true;
	else
		return false;
}

bool comp(const TreeInfo &treeInfo1, const TreeInfo &treeInfo2) {
	if (treeInfo1.age < treeInfo2.age)
		return true;
	else
		return false;
}

/* 봄 작업 처리 */
void spring() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			vector<TreeInfo> treeInfos = trees[r][c];
			int len = treeInfos.size();

			sort(treeInfos.begin(), treeInfos.end(), comp);

			for (int i = 0; i < len; i++) {
				if (foods[r][c] - treeInfos[i].age >= 0) {
					foods[r][c] -= treeInfos[i].age;
					treeInfos[i].age += 1;
				}
				else {
					treeInfos[i].isAlive = false;
				}
			}

			// 나무 정보 갱신!
			trees[r][c] = treeInfos;
		}
	}
}

/* 여름 작업 처리 */
void summer() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			vector<TreeInfo> treeInfos = trees[r][c];
			int len = treeInfos.size();
			vector<TreeInfo> aliveTrees;

			int sum = 0;	// 봄에 죽은 나무의 양분 더해주기
			
			for (int i = 0; i < len; i++) {
				if (treeInfos[i].isAlive)
					aliveTrees.push_back(treeInfos[i]);
				else
					sum += treeInfos[i].age / 2;
			}

			foods[r][c] += sum;		// 양분 추가

			trees[r][c] = aliveTrees;	// 살아있는 나무로만 교체
		}
	}
}

/* 가을 작업 처리 */
void fall() {
	copyTreesToTemp();

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			vector<TreeInfo> treeInfos = trees[r][c];
			int len = treeInfos.size();

			for (int i = 0; i < len; i++) {
				int age = treeInfos[i].age;

				// 나이가 5의 배수인 나무만 번식한다.
				if (age % 5 != 0) continue;

				for (int k = 0; k < 8; k++) {
					int nr = r + dr[k];
					int nc = c + dc[k];

					if (!isInside(nr, nc)) continue;

					// 나이가 1인 나무 생성
					temp[nr][nc].push_back({ true, 1 });
				}
			}
		}
	}

	copyTempToTrees();
}

/* 겨울 작업 처리 */
void winter() {
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			foods[r][c] += A[r][c];
}

/* 1년(4계절) 시뮬레이션 */
void simulation() {
	spring();
	summer();
	fall();
	winter();
}

/* 살아있는 나무 세기 */
int countAliveTrees() {
	int sum = 0;

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			sum += trees[r][c].size();

	return sum;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	for (int k = 0; k < K; k++)
		simulation();

	cout << countAliveTrees() << '\n';

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
	각 열을 갱신하기 위한 배열
	flag 배열에서 2인 것만 골라서 temp 배열의
	뒤에서부터 집어 넣어주고 나머지 값은 점으로
	만들어서 저장
*/
vector<char> temp;

/*
	터지는 여부를 담기 위한 배열
	4개 미만이면 false, 4개 이상이면 true 저장
*/
bool flag[12][6];

/*
	4개 이상이 하나라도 생기면,
	replay를 true로 만들어준다.

	탐색을 돌고서 replay가 true이면
	연쇄의 횟수를 추가해주고,
	false라면 터진 것이 하나도 없는 것이므로
	종료한다.
*/
bool replay;

bool check[12][6];	// 방문 여부
int cnt = 0;	// 연쇄 횟수
string a[12];	// 뿌요의 초기 정보(map 정보)

/*
	상 하 좌 우 탐색용 배열
*/
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 전역 변수 배열 초기화
void Init() {
	replay = false;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			check[i][j] = false;
			flag[i][j] = false;
		}
	}
}

void BFS(int x, int y, char color) {
	vector<pair<int, int>> v;	// 탐색 기준 색상들의 좌표를 담기 위한 벡터
	queue<pair<int, int>> q;
	int count = 1;

	q.push(make_pair(x, y));
	v.push_back(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < 12 && 0 <= ny && ny < 6) {
				if (a[nx][ny] == color && !check[nx][ny]) {
					q.push(make_pair(nx, ny));
					v.push_back(make_pair(nx, ny));
					check[nx][ny] = true;
					count += 1;
				}
			}
		}
	}

	// 탐색을 다 돌고 4개 이상의 인접 색깔이 있다면
	if (count >= 4) {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;

			flag[x][y] = true;
		}

		replay = true;
	}
}

int main() {
	for (int i = 0; i < 12; i++)
		cin >> a[i];

	while (true) {
		Init();

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
				if (a[i][j] != '.' && !check[i][j])
					BFS(i, j, a[i][j]);

		// 4개 이상이어서 터지는 영역이 하나라도 있으면
		// 연쇄 횟수 증가 후 맵 다시 그리기
		if (replay) {
			cnt += 1;

			for (int i = 0; i < 6; i++) {
				int count = 0;

				for (int j = 11; j >= 0; j--) {
					// 터지지 않아 그대로 남아 있는 부분이라면
					if (!flag[j][i])
						temp.push_back((char)a[j][i]);
					else
						// 터지는 부분이라면 해당 열의 그 개수 세기
						count += 1;
				}

				// 나머지 부분 점으로 채우기
				for (int j = 0; j < count; j++)
					temp.push_back('.');

				// 그러면 해당 열의 새로 그리는 값이 temp에 담겼다.
				// a를 다시 그려주자
				for (int j = 0; j < 12; j++)
					a[j][i] = temp[11 - j];

				// a의 해당 열을 다시 그려줬으면 temp 클리어!
				temp.clear();
			}
		}
		else
			break;
	}

	cout << cnt << endl;

	return 0;
}
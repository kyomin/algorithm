#include <iostream>

using namespace std;

int isItRobot[101][101];	// 0이면 없고 아니면 번호
pair<int, int> robotPositions[101];
int robotDirection[101];

// 0 : N, 1 : E, 2 : S, 3 : W
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int N, M, X, Y;
bool isCrushed = false;
string result;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> X >> Y;
	cin >> N >> M;

	// 로봇 정보 입력!
	for (int i = 1; i <= N; i++) {
		int x, y;
		char dir;
		cin >> x >> y >> dir;

		// 인덱스 맞춰주기 위함!
		y = Y - y + 1;

		robotPositions[i] = make_pair(x, y);
		isItRobot[y][x] = i;

		switch (dir) {
		case 'N':
			robotDirection[i] = 0;
			break;

		case 'E':
			robotDirection[i] = 1;
			break;

		case 'S':
			robotDirection[i] = 2;
			break;

		case 'W':
			robotDirection[i] = 3;
			break;
		}
	}

	// 명령 수행!
	for (int m = 0; m < M; m++) {
		int robot, repeat;
		char command;

		cin >> robot >> command >> repeat;

		if (command == 'F') {
			int x = robotPositions[robot].first;
			int y = robotPositions[robot].second;
			int dir = robotDirection[robot];

			for (int i = 1; i <= repeat; i++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				// 벽에 충돌하는 경우
				if (nx < 1 || nx > X || ny > Y || ny < 1) {
					cout << "Robot " << robot << " crashes into the wall" << endl;
					return 0;
				}

				// 로봇과 만나는 경우
				if (isItRobot[ny][nx] != 0) {
					cout << "Robot " << robot << " crashes into robot " << isItRobot[ny][nx] << '\n';
					return 0;
				}

				// 이동하므로
				isItRobot[y][x] = 0;
				isItRobot[ny][nx] = robot;
				robotPositions[robot] = make_pair(nx, ny);
				x = nx;
				y = ny;
			}
		}
		else if (command == 'L') {
			int dir = robotDirection[robot];

			for (int i = 1; i <= repeat; i++) {
				dir -= 1;

				if (dir == -1)
					dir = 3;
			}

			robotDirection[robot] = dir;
		}
		else if (command == 'R') {
			int dir = robotDirection[robot];

			for (int i = 1; i <= repeat; i++) {
				dir += 1;

				if (dir == 4)
					dir = 0;
			}

			robotDirection[robot] = dir;
		}
	}

	cout << "OK" << '\n';

	return 0;
}
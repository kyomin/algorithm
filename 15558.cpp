#include <iostream>
#include <string>

using namespace std;

string lines[2];
bool result = false;
bool visit[2][100000];
int N, K;

// position : 현재 칸, start : 줄의 시작 칸, line : 현재 라인
void go(int pos, int start, int line) {
	visit[line][pos] = true;

	/*	case 1	*/
	if (pos + 1 >= N) {		// N칸보다 더 큰 칸으로 이동하는 경우
		result = true;
		return;
	}

	// 다음 칸으로 이동할 수 있는 경우
	if (lines[line][pos + 1] == '1' && !visit[line][pos + 1]) {
		go(pos + 1, start + 1, line);
	}


	/*	case 2	*/
	if (pos - 1 >= start + 1 && lines[line][pos - 1] == '1' && !visit[line][pos - 1]) {
		go(pos - 1, start + 1, line);
	}


	/*	case 3	*/
	if (pos + K >= N) {		// N칸보다 더 큰 칸으로 이동하는 경우
		result = true;
		return;
	}

	// 반대쪽 라인의 K 다음 칸으로 이동할 수 있는 경우
	if (line == 0) {
		if (lines[1][pos + K] == '1' && !visit[1][pos + K]) {
			go(pos + K, start + 1, 1);
		}
	}
	else {
		if (lines[0][pos + K] == '1' && !visit[0][pos + K]) {
			go(pos + K, start + 1, 0);
		}
	}
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < 2; i++) {
		cin >> lines[i];
	}

	go(0, 0, 0);

	if (result)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}
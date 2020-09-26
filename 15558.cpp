#include <iostream>
#include <string>

using namespace std;

string lines[2];
bool result = false;
bool visit[2][100000];
int N, K;

// position : ���� ĭ, start : ���� ���� ĭ, line : ���� ����
void go(int pos, int start, int line) {
	visit[line][pos] = true;

	/*	case 1	*/
	if (pos + 1 >= N) {		// Nĭ���� �� ū ĭ���� �̵��ϴ� ���
		result = true;
		return;
	}

	// ���� ĭ���� �̵��� �� �ִ� ���
	if (lines[line][pos + 1] == '1' && !visit[line][pos + 1]) {
		go(pos + 1, start + 1, line);
	}


	/*	case 2	*/
	if (pos - 1 >= start + 1 && lines[line][pos - 1] == '1' && !visit[line][pos - 1]) {
		go(pos - 1, start + 1, line);
	}


	/*	case 3	*/
	if (pos + K >= N) {		// Nĭ���� �� ū ĭ���� �̵��ϴ� ���
		result = true;
		return;
	}

	// �ݴ��� ������ K ���� ĭ���� �̵��� �� �ִ� ���
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
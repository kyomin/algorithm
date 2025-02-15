#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	stack<int> basket;
	int Y = board.size();
	int len = moves.size();

	for (int i = 0; i < len; i++) {
		int move = moves[i];
		move--;		// �ε��� ���߱� ����

		int doll = 0;

		for (int y = 0; y < Y; y++) {
			// ũ������ �ش� ��ġ���� ������ ������ ������
			if (board[y][move] != 0) {
				doll = board[y][move];
				board[y][move] = 0;		// �� ĭ���� ����� �ش�.
				break;
			}
		}

		// �ش� ��ġ�� ũ������ ���ȴµ� ������ ���� ���
		if (doll == 0)
			continue;

		// ������ ��� �ִٸ� �׳� �־��ش�.
		if (basket.size() == 0) {
			basket.push(doll);
			continue;
		}

		// ���� ���� ������ ������ �ȴٸ�
		if (basket.top() == doll) {
			answer += 2;
			basket.pop();
		}
		else {
			basket.push(doll);
		}
	}

	return answer;
}
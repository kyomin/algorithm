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
		move--;		// 인덱스 맞추기 위함

		int doll = 0;

		for (int y = 0; y < Y; y++) {
			// 크레인을 해당 위치에서 내려서 인형을 만나면
			if (board[y][move] != 0) {
				doll = board[y][move];
				board[y][move] = 0;		// 빈 칸으로 만들어 준다.
				break;
			}
		}

		// 해당 위치에 크레인을 내렸는데 인형이 없는 경우
		if (doll == 0)
			continue;

		// 스택이 비어 있다면 그냥 넣어준다.
		if (basket.size() == 0) {
			basket.push(doll);
			continue;
		}

		// 서로 같은 인형을 만나게 된다면
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
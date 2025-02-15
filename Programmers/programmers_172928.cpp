#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;
	pair<int, int> curPos;
	int R;
	int C;

	R = park.size();
	C = park[0].length();

	for (int r = 0; r < R; r++) {
		bool found = false;

		for (int c = 0; c < C; c++) {
			if (park[r][c] == 'S') {
				curPos.first = r;
				curPos.second = c;
				found = true;
				break;
			}
		}

		if (found)
			break;
	}

	int len = routes.size();
	for (int i = 0; i < len; i++) {
		string route = routes[i];
		char direction = route[0];
		int num = (int)(route[2] - '0');
		int r = curPos.first;
		int c = curPos.second;
		bool isValid = true;

		if (direction == 'E') {
			for (int i = 0; i < num; i++) {
				c += 1;

				if (c >= C || park[r][c] == 'X') {
					isValid = false;
					break;
				}
			}
		}
		else if (direction == 'W') {
			for (int i = 0; i < num; i++) {
				c -= 1;

				if (c < 0 || park[r][c] == 'X') {
					isValid = false;
					break;
				}
			}
		}
		else if (direction == 'N') {
			for (int i = 0; i < num; i++) {
				r -= 1;

				if (r < 0 || park[r][c] == 'X') {
					isValid = false;
					break;
				}
			}
		}
		else if (direction == 'S') {
			for (int i = 0; i < num; i++) {
				r += 1;

				if (r >= R || park[r][c] == 'X') {
					isValid = false;
					break;
				}
			}
		}

		if (isValid) {
			curPos.first = r;
			curPos.second = c;
		}
	}

	answer.push_back(curPos.first);
	answer.push_back(curPos.second);

	return answer;
}
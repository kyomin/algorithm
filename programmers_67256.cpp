#include <string>
#include <vector>

using namespace std;

/*
	2 5 8 0 과의 거리를 담을 룩업 테이블
	table[i][j] : i -> j 까지의 거리
	* : 10, # : 11
*/
int table[12][12];

void initTable() {
	table[1][2] = 1;
	table[1][5] = 2;
	table[1][8] = 3;
	table[1][0] = 4;

	table[4][2] = 2;
	table[4][5] = 1;
	table[4][8] = 2;
	table[4][0] = 3;

	table[7][2] = 3;
	table[7][5] = 2;
	table[7][8] = 1;
	table[7][0] = 2;

	table[10][2] = 4;
	table[10][5] = 3;
	table[10][8] = 2;
	table[10][0] = 1;

	table[2][5] = 1;
	table[5][2] = 1;
	table[2][8] = 2;
	table[8][2] = 2;
	table[2][0] = 3;
	table[0][2] = 3;
	
	table[5][8] = 1;
	table[8][5] = 1;
	table[5][0] = 2;
	table[0][5] = 2;
	
	table[8][0] = 1;
	table[0][8] = 1;

	table[3][2] = 1;
	table[3][5] = 2;
	table[3][8] = 3;
	table[3][0] = 4;

	table[6][2] = 2;
	table[6][5] = 1;
	table[6][8] = 2;
	table[6][0] = 3;

	table[9][2] = 3;
	table[9][5] = 2;
	table[9][8] = 1;
	table[9][0] = 2;

	table[11][2] = 4;
	table[11][5] = 3;
	table[11][8] = 2;
	table[11][0] = 1;
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int len = numbers.size();
	int cur_left = 10;
	int cur_right = 11;

	initTable();

	for (int i = 0; i < len; i++) {
		int number = numbers[i];

		// 왼손 엄지만 사용하는 경우
		if (number == 1 || number == 4 || number == 7) {
			answer += "L";
			cur_left = number;
			continue;
		}

		// 오른손 엄지만 사용하는 경우
		if (number == 3 || number == 6 || number == 9) {
			answer += "R";
			cur_right = number;
			continue;
		}

		// 2 5 8 0이 눌린 경우라면
		if (table[cur_left][number] < table[cur_right][number]) {
			// 현재 왼손이 더 가까운 경우
			answer += "L";
			cur_left = number;
		}
		else if (table[cur_left][number] > table[cur_right][number]) {
			// 현재 오른손이 더 가까운 경우
			answer += "R";
			cur_right = number;
		}
		else {
			// 가까운 정도가 같은 경우
			if (hand == "right") {
				answer += "R";
				cur_right = number;
			}
			else {
				answer += "L";
				cur_left = number;
			}
		}
	}

	return answer;
}
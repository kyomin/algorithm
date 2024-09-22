#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> split(string str, char delimiter) {
	vector<int> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter))
		internal.push_back(atoi(temp.c_str()));

	return internal;
}

// 계산의 편의를 위해 초로 환산해 받는다
bool isInOpening(int op_start_s, int op_end_s, int pos_s) {
	if (op_start_s <= pos_s && op_end_s >= pos_s)
		return true;

	return false;
}

string formatWithLeadingZero(int num) {
	// 숫자가 10보다 작으면 앞에 0을 붙임
	if (num < 10) {
		return "0" + to_string(num);
	}
	else {
		return to_string(num);
	}
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
	vector<int> video_arr = split(video_len, ':');
	vector<int> pos_arr = split(pos, ':');
	vector<int> op_start_arr = split(op_start, ':');
	vector<int> op_end_arr = split(op_end, ':');

	int op_start_s = (op_start_arr[0] * 60) + op_start_arr[1];
	int op_end_s = (op_end_arr[0] * 60) + op_end_arr[1];

	for (string command : commands) {
		int pos_mm = pos_arr[0];
		int pos_ss = pos_arr[1];
		int pos_s = (pos_mm * 60) + pos_ss;

		// 명령 실행 전 현재 오프닝 구간에 있다면 건너뛴다
		if (isInOpening(op_start_s, op_end_s, pos_s)) {
			pos_mm = op_end_arr[0];
			pos_ss = op_end_arr[1];
		}

		if (command == "next") {
			pos_ss += 10;

			int carry = pos_ss / 60;

			pos_mm += carry;
			pos_ss %= 60;

			pos_s = (pos_mm * 60) + pos_ss;

			// 오프닝 구간에 있다면
			if (isInOpening(op_start_s, op_end_s, pos_s)) {
				pos_mm = op_end_arr[0];
				pos_ss = op_end_arr[1];
			}

			// 동영상 종료 시간을 넘어섰다면
			if (video_arr[0] < pos_mm || (video_arr[0] == pos_mm && video_arr[1] < pos_ss)) {
				pos_mm = video_arr[0];
				pos_ss = video_arr[1];
			}
		}
		else {
			pos_s -= 10;

			// 오프닝 구간에 있다면
			if (isInOpening(op_start_s, op_end_s, pos_s)) {
				pos_mm = op_end_arr[0];
				pos_ss = op_end_arr[1];
			}
			// 동영상 시작 시간 이전으로 이동한 경우
			else if (pos_s < 0) {
				pos_mm = 0;
				pos_ss = 0;
			}
			// 그 외의 경우 분/초로 환산
			else {
				pos_mm = pos_s / 60;
				pos_ss = pos_s % 60;
			}
		}

		// Update!
		pos_arr[0] = pos_mm;
		pos_arr[1] = pos_ss;
	}

	string mm_str = formatWithLeadingZero(pos_arr[0]);
	string ss_str = formatWithLeadingZero(pos_arr[1]);

	string answer = mm_str + ":" + ss_str;

	return answer;
}
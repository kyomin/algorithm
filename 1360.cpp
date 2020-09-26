#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<string> status;
	status.push_back("");

	int prevTime = 0;

	for (int n = 0; n < N; n++) {
		string command, val;
		int time;

		cin >> command >> val >> time;

		if (command == "type") {
			// 이전 상태 추출
			string prevStatus = status[prevTime];
			
			// 현재 상태 갱신
			string curStatus = prevStatus + val;

			// 중간에 명령이 없는 시간까지 고려
			for (int i = prevTime; i < time-1; i++) {
				status.push_back(prevStatus);
			}

			status.push_back(curStatus);

			prevTime = time;
		}
		else {
			// 이전 상태 추출
			string prevStatus = status[prevTime];

			// 중간에 명령이 없는 시간까지 고려
			for (int i = prevTime; i < time - 1; i++) {
				status.push_back(prevStatus);
			}

			// 현재 상태 갱신
			string curStatus = status[time - atoi(val.c_str()) - 1];
			status.push_back(curStatus);

			prevTime = time;
		}
	}

	cout << status[prevTime] << '\n';

	return 0;
}
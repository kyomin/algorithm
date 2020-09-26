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
			// ���� ���� ����
			string prevStatus = status[prevTime];
			
			// ���� ���� ����
			string curStatus = prevStatus + val;

			// �߰��� ����� ���� �ð����� ���
			for (int i = prevTime; i < time-1; i++) {
				status.push_back(prevStatus);
			}

			status.push_back(curStatus);

			prevTime = time;
		}
		else {
			// ���� ���� ����
			string prevStatus = status[prevTime];

			// �߰��� ����� ���� �ð����� ���
			for (int i = prevTime; i < time - 1; i++) {
				status.push_back(prevStatus);
			}

			// ���� ���� ����
			string curStatus = status[time - atoi(val.c_str()) - 1];
			status.push_back(curStatus);

			prevTime = time;
		}
	}

	cout << status[prevTime] << '\n';

	return 0;
}
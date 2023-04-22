#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

struct Task {
	int score;
	int time;
};

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int main() {
	int totalScore = 0;
	int N;
	stack<Task> scheduler;

	cin >> N;
	cin.get();

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);

		vector<string> infos = split(str, ' ');

		if (infos.size() == 1) {
			if (scheduler.empty())
				continue;

			scheduler.top().time -= 1;

			if (scheduler.top().time == 0) {
				totalScore += scheduler.top().score;
				scheduler.pop();
			}
		}
		else {
			int score = atoi(infos[1].c_str());
			int time = atoi(infos[2].c_str());

			time -= 1;

			if (time == 0) {
				totalScore += score;
			}
			else {
				Task task;
				task.score = score;
				task.time = time;
				scheduler.push(task);
			}
		}
	}

	cout << totalScore << endl;

	return 0;
}
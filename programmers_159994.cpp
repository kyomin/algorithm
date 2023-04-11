#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	string answer = "";
	queue<string> q1;
	queue<string> q2;
	queue<string> q_goal;
	int turn = 1;
	bool flag = true;

	for (int i = 0; i < cards1.size(); i++)
		q1.push(cards1[i]);

	for (int i = 0; i < cards2.size(); i++)
		q2.push(cards2[i]);

	for (int i = 0; i < goal.size(); i++)
		q_goal.push(goal[i]);

	while (!q_goal.empty()) {
		if (q1.front() != q_goal.front() && q2.front() != q_goal.front()) {
			flag = false;
			break;
		}

		if (turn == 1) {
			if (q1.front() == q_goal.front()) {
				q1.pop();
				q_goal.pop();
				continue;
			}
			else {
				turn = 2;
			}
		}
		else {
			if (q2.front() == q_goal.front()) {
				q2.pop();
				q_goal.pop();
				continue;
			}
			else {
				turn = 1;
			}
		}		
	}

	if (flag)
		answer = "Yes";
	else
		answer = "No";

	return answer;
}
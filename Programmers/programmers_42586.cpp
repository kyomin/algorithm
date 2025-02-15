#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int len = progresses.size();
	int *A = new int[len];

	for (int i = 0; i < len; i++) {
		int num = 100 - progresses[i];

		if (num % speeds[i] == 0)
			A[i] = num / speeds[i];
		else
			A[i] = (num / speeds[i]) + 1;
	}

	int deadline = A[0];

	for (int i = 1; i < len; i++) {
		if (deadline >= A[i])
			A[i] = deadline;
		else
			deadline = A[i];
	}

	int cnt = 1;
	int group = A[0];


	for (int i = 1; i < len; i++) {
		if (A[i] == A[i - 1])
			cnt++;
		else {
			answer.push_back(cnt);
			cnt = 1;
		}
	}

	answer.push_back(cnt);

	return answer;
}
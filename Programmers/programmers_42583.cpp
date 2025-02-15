#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int idx = 0;
	int sum = 0;
	queue<int> q;

	while (1) {
		// last truck
		if (idx == truck_weights.size()) {
			answer += bridge_length;
			break;
		}

		answer++;
		int tmp = truck_weights[idx];

		if (q.size() == bridge_length) {
			sum -= q.front();
			q.pop();
		}

		if (sum + tmp <= weight) {
			sum += tmp;
			q.push(tmp);
			idx++;	// for next truck
		}
		else {
			q.push(0);	// temp value for time
		}
	}

	return answer;
}
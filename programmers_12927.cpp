#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	int len = works.size();

	for (int i = 0; i < len; i++)
		pq.push(works[i]);

	for (int i = 0; i < n; i++) {
		int temp = pq.top();

		if (temp == 0) break;

		pq.pop();
		temp -= 1;
		pq.push(temp);
	}

	while (!pq.empty()) {
		answer += (pq.top()*pq.top());
		pq.pop();
	}

	return answer;
}
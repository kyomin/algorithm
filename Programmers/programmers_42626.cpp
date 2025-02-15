#include <string>
#include <vector>
#include <queue>

using namespace std;

// 최소 힙!
priority_queue<int, vector<int>, greater<int>> pq;

int makeNewFood(int n1, int n2) {
	return n1 + (n2 * 2);
}

int solution(vector<int> scoville, int K) {
	int answer = 0;

	int len = scoville.size();

	// 최소 힙에 저장 작업!
	for (int i = 0; i < len; i++)
		pq.push(scoville[i]);

	while (true) {
		// 큐에 하나만 남게 된다면
		if (pq.size() == 1)
			break;

		// 최소 값이 K 이상이면
		if (pq.top() >= K)
			break;

		// 위의 경우에 걸리지 않는다면 섞는다!
		int food1, food2;

		food1 = pq.top();

		pq.pop();

		food2 = pq.top();

		pq.pop();

		int newFood = makeNewFood(food1, food2);

		pq.push(newFood);

		answer++;
	}


	if (pq.top() < K)
		answer = -1;

	return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

// �ּ� ��!
priority_queue<int, vector<int>, greater<int>> pq;

int makeNewFood(int n1, int n2) {
	return n1 + (n2 * 2);
}

int solution(vector<int> scoville, int K) {
	int answer = 0;

	int len = scoville.size();

	// �ּ� ���� ���� �۾�!
	for (int i = 0; i < len; i++)
		pq.push(scoville[i]);

	while (true) {
		// ť�� �ϳ��� ���� �ȴٸ�
		if (pq.size() == 1)
			break;

		// �ּ� ���� K �̻��̸�
		if (pq.top() >= K)
			break;

		// ���� ��쿡 �ɸ��� �ʴ´ٸ� ���´�!
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
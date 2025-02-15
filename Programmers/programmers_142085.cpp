#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < enemy.size(); i++) {
		int e = enemy[i];
		pq.push(e);

		// k만큼 들어온 것 중 큰 것들로 유지
		if (pq.size() > k) {
			sum += pq.top();
			pq.pop();
		}

		// 다음 라운드로 못 가는 경우
		if (sum > n)
			return i;
	}

	return enemy.size();
}
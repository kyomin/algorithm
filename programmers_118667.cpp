#include <string>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = 0;
	int N = queue1.size();
	
	long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
	long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);

	// 홀수일 경우 서로 같은 합을 갖도록 만들 수 없다.
	if ((sum1 + sum2) % 2 == 1)
		return -1;

	deque<int> dq1(queue1.begin(), queue1.end());
	deque<int> dq2(queue2.begin(), queue2.end());

	for (int i = 0; i < N * 4; i++) {
		if (sum1 == sum2)
			return answer;

		if (sum1 > sum2) {
			int num = dq1.front();

			dq1.pop_front();
			dq2.push_back(num);

			sum1 -= num;
			sum2 += num;
		}
		else {
			int num = dq2.front();

			dq2.pop_front();
			dq1.push_back(num);

			sum1 += num;
			sum2 -= num;
		}

		answer++;
	}

	return -1;
}
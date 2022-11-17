#include <string>
#include <vector>

using namespace std;

int getNumberOfDevisor(int num) {
	int cnt = 0;

	for (int i = 1; i*i <= num; i++) {
		if (num%i == 0) {
			cnt++;

			if (i*i < num)
				cnt++;
		}
	}

	return cnt;
}

int solution(int number, int limit, int power) {
	int answer = 0;
	vector<int> knights;
	knights.resize(number);

	for (int i = 1; i <= number; i++)
		knights[i - 1] = getNumberOfDevisor(i);

	for (int i = 0; i < number; i++) {
		int knight = knights[i];

		if (knight <= limit)
			answer += knight;
		else
			answer += power;
	}

	return answer;
}
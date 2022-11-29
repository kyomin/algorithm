#include <string>
#include <vector>
using namespace std;

vector<int> solution(int num, int total) {
	vector<int> answer;
	int start = (num / 2)*(-1);

	while (true) {
		int sum = 0;

		for (int i = start; i < start + num; i++)
			sum += i;

		if (sum == total) {
			for (int i = start; i < start + num; i++)
				answer.push_back(i);

			break;
		}

		start += 1;
	}

	return answer;
}
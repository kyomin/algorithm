#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;

	int len = arr.size();

	// 일단 첫 번째 원소는 집어넣기!
	answer.push_back(arr[0]);

	for (int i = 1; i < len; i++)
		// 이전 원소하고 연속되지 않을 때만 집어넣기!
		if (arr[i] != arr[i - 1])
			answer.push_back(arr[i]);

	return answer;
}
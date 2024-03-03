#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
	vector<int> answer(arr.begin(), arr.end());

	int size = query.size();
	for (int i = 0; i < size; i++) {
		vector<int> temp;

		int index = query[i];

		if (i % 2 == 0) {
			for (int j = 0; j <= index; j++)
				temp.push_back(answer[j]);			
		}
		else {
			for (int j = index; j < answer.size(); j++)
				temp.push_back(answer[j]);
		}

		answer = temp;
	}

	return answer;
}
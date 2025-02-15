#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	int len = commands.size();

	for (int i = 0; i < len; i++) {
		int start = commands[i][0] - 1;
		int end = commands[i][1];
		vector<int> temp;

		for (int j = start; j < end; j++)
			temp.push_back(array[j]);

		sort(temp.begin(), temp.end());

		answer.push_back(temp[commands[i][2] - 1]);
	}

	return answer;
}
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> array) {
	vector<int> answer;
	answer.resize(2);
	int len = array.size();
	int max = -1;

	for (int i = 0; i < len; i++) {
		int num = array[i];
		
		if (num > max) {
			max = num;
			answer[0] = max;
			answer[1] = i;
		}
	}

	return answer;
}
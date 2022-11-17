#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
	string answer = "";
	string temp = "";
	int len = food.size();

	for (int i = 1; i < len; i++) {
		int num = food[i];

		if (num < 2)
			continue;

		int q = num / 2;

		for (int j = 0; j < q; j++)
			temp += to_string(i);
	}

	answer += temp;
	answer += "0";
	reverse(temp.begin(), temp.end());
	answer += temp;

	return answer;
}
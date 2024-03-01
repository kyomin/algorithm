#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
	string answer(my_string.begin(), my_string.end());

	for (vector<int> query : queries) {
		int s = query[0];
		int e = query[1];

		// 시작과 끝 반복자 얻기
		auto start_iter = answer.begin() + s;
		auto end_iter = answer.begin() + e + 1;

		reverse(start_iter, end_iter);
	}

	return answer;
}
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> vc;
set<int> s;
int N;

void dfs(int cnt, vector<int> numbers) {
	if (vc.size() == 2) {
		int sum = vc[0] + vc[1];
		s.insert(sum);

		return;
	}

	for (int i = cnt; i < N; i++) {
		if (vc.size() < 2) {
			vc.push_back(numbers[i]);
			dfs(i + 1, numbers);
			vc.pop_back();
		}
	}
}

vector<int> solution(vector<int> numbers) {
	N = numbers.size();
	dfs(0, numbers);

	vector<int> answer(s.begin(), s.end());

	return answer;
}
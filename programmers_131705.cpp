#include <string>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> comb;
int cnt = 0;
int N;

void dfs(int idx) {
	if (comb.size() == 3) {
		int sum = 0;

		for (auto num : comb)
			sum += num;
		
		if (sum == 0)
			cnt++;

		return;
	}

	for (int i = idx; i < N; i++) {
		if (comb.size() < 3) {
			comb.push_back(nums[i]);
			dfs(i + 1);
			comb.pop_back();
		}
	}
}

int solution(vector<int> number) {
	nums = number;
	N = number.size();

	dfs(0);

	return cnt;
}
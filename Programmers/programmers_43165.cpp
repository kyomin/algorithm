#include <string>
#include <vector>

using namespace std;

int ans = 0;

void dfs(int sum, int target, vector<int> numbers, int idx) {
	if (idx >= numbers.size()) {
		if (sum == target)
			ans++;

		return;
	}

	dfs(sum + numbers[idx], target, numbers, idx + 1);
	dfs(sum - numbers[idx], target, numbers, idx + 1);
}


int solution(vector<int> numbers, int target) {
	dfs(0, target, numbers, 0);

	return ans;
}
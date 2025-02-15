#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
	int answer = 0;
	set<int> s;
	int N = nums.size();

	for (int n = 0; n < N; n++)
		s.insert(nums[n]);

	if (s.size() < (N / 2))
		answer = s.size();
	else
		answer = (N / 2);

	return answer;
}
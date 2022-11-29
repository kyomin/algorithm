#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
	set<int> results;
	vector<int> nums;
	vector<int> pSum;

	for (int i = 0; i < elements.size(); i++)
		nums.push_back(elements[i]);

	for (int i = 0; i < elements.size() - 1; i++)
		nums.push_back(elements[i]);

	pSum.resize(elements.size() * 2);
	pSum[0] = 0;

	for (int i = 0; i < nums.size(); i++)
		pSum[i + 1] = nums[i] + pSum[i];

	for (int len = 1; len <= elements.size(); len++) {
		for (int i = 0; i < nums.size(); i++) {
			if (i + len >= pSum.size())
				break;

			results.insert(pSum[i + len] - pSum[i]);
		}
	}

	return results.size();
}
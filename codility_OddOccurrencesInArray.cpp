#include <vector>

using namespace std;

int solution(vector<int> &A) {
	int ans = 0;
	int len = A.size();

	for (int i = 0; i < len; i++)
		ans = ans ^ A[i];

	return ans;
}
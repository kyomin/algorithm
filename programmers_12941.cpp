#include <vector>
#include <algorithm>

using namespace std;

bool comp(const int &n1, const int &n2) {
	if (n1 > n2)
		return true;
	else
		return false;
}

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	int len = A.size();

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), comp);

	for (int i = 0; i < len; i++)
		answer += (A[i] * B[i]);
	
	return answer;
}
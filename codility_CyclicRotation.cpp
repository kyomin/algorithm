#include <vector>

using namespace std;

void rotate(vector<int> &A) {
	int len = A.size();
	int temp = A[len-1];

	for (int i = len-1; i >= 1; i--) 
		A[i] = A[i - 1];

	A[0] = temp;
}

vector<int> solution(vector<int> &A, int K) {
	int len = A.size();

	if (len == 0)
		return {};

	for (int k = 0; k < K; k++)
		rotate(A);

	return A;
}
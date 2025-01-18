#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	int count = 0;
	int start = 0;
	int end = N - 1;

	while (start < end) {
		if (A[start] + A[end] < M)
			start++;
		else if (A[start] + A[end] > M)
			end--;
		else {
			count++;
			start++;
			end--;
		}
	}

	cout << count << endl;

	return 0;
}
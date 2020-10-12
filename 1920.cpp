#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Binary Search function
bool BSearch(int *ptr, int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid = 0;

	while (first <= last) {
		mid = (first + last) / 2;
		
		if (ptr[mid] == target) 
			return true;
		else
			if (ptr[mid] > target)
				last = mid - 1;
			else
				first = mid + 1;
	}

	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N;

	int *A = new int[N];

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		A[i] = n;
	}

	cin >> M;

	int *B = new int[M];

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		B[i] = n;
	}

	sort(A, A + N);

	for (int i = 0; i < M; i++)
		if (BSearch(A, N, B[i]))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

	return 0;
}
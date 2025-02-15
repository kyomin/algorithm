#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool rev(int n1, int n2) {
	if (n1 > n2)
		return true;
	else
		return false;
}

int main() {
	vector<int> A;
	vector<int> B;
	
	int N;
	cin >> N;

	A.resize(N);
	B.resize(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), rev);

	int sum = 0;

	for (int i = 0; i < N; i++)
		sum += A[i] * B[i];

	cout << sum << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	const int MAX_P = 200;
	int P, N;
	cin >> P >> N;

	vector<int> A(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		if (P >= MAX_P)
			break;

		ans++;
		
		P += A[i];
	}

	cout << ans << endl;

	return 0;
}
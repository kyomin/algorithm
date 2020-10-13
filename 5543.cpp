#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;
	int *A = new int[5];

	for (int i = 0; i < 5; i++)
		cin >> A[i];

	for (int i = 3; i <= 4; i++)
		for (int j = 0; j <= 2; j++)
			v.push_back(A[i] + A[j]);
		
	sort(v.begin(), v.end());

	cout << v[0] - 50 << endl;

	return 0;
}
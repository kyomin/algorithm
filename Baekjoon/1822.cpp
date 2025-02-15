#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	vector<int> result;
	set<int> A, B;
	int numOfA, numOfB;

	cin >> numOfA >> numOfB;

	for (int i = 0; i < numOfA; i++) {
		int n;
		cin >> n;

		A.insert(n);
	}

	for (int i = 0; i < numOfB; i++) {
		int n;
		cin >> n;

		B.insert(n);
	}

	set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));

	// Output
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1)
			cout << result[i] << endl;
		else
			cout << result[i] << ' ';
	}

	return 0;
}
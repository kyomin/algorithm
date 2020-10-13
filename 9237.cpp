#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const int &n1, const int &n2) {
	if (n1 > n2)
		return true;
	else
		return false;
}

int main() {
	int N;
	vector<int> v, temp;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		v.push_back(n);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++)
		temp.push_back(
			i + 1 + v[i] + 1
		);

	cout << *max_element(temp.begin(), temp.end()) << endl;

	return 0;
}
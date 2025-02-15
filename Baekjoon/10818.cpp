#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	int max = v[0];
	int min = v[0];
	int len = v.size();

	for (int i = 1; i < len; i++) {
		if (v[i] > max)
			max = v[i];

		if (v[i] < min)
			min = v[i];
	}

	cout << min << ' ' << max << endl;

	return 0;
}
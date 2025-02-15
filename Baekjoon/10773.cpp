#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n != 0)
			v.push_back(n);
		else
			v.pop_back();
	}

	int len = v.size();
	int sum = 0;

	for (int i = 0; i < len; i++)
		sum += v[i];

	cout << sum << endl;

	return 0;
}
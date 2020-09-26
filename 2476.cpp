#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> results;

	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		vector<int> v;
		v.resize(3);

		for (int i = 0; i < 3; i++) {
			cin >> v[i];
		}

		int result;

		// ¸ðµÎ °°Àº ´«
		if (v[0] == v[1] && v[1] == v[2] && v[0] == v[2]) {
			result = 10000 + (v[0] * 1000);
		}
		else if (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]) {	// ¸ðµÎ ´Ù¸¥ ´«
			result = *max_element(v.begin(), v.end()) * 100;
		}
		else {		// 2°³¸¸ °°Àº ´«
			if (v[0] == v[1])
				result = 1000 + v[0] * 100;
			else if(v[1] == v[2])
				result = 1000 + v[1] * 100;
			else
				result = 1000 + v[0] * 100;
		}

		results.push_back(result);
	}

	cout << *max_element(results.begin(), results.end());

	return 0;
}
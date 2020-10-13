#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string s1, s2;
		cin >> s1 >> s2;

		int len = s1.size();
		vector<int> v;

		for (int i = 0; i < len; i++)
			if (s1[i] <= s2[i])
				v.push_back(
					(int)(s2[i] - s1[i])
				);
			else
				v.push_back(
					(int)(s2[i] - s1[i]) + 26
				);

		cout << "Distances: ";

		for (int i = 0; i < len; i++)
			cout << v[i] << ' ';

		cout << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;

	for (int i = 0; i < 4; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		if (i == 0)
			v.push_back(n2 - n1);
		else
			v.push_back(v[i - 1] + n2 - n1);
	}

	int len = v.size();
	int max = v[0];

	for (int i = 1; i < len; i++)
		if (max < v[i])
			max = v[i];
		
	cout << max << endl;

	return 0;
}
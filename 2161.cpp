#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v1;
	vector<int> v2;

	for (int i = 1; i <= n; i++)
		v1.push_back(i);

	vector<int>::iterator iter;

	while (v1.size() != 1) {
		v2.push_back(v1[0]);

		iter = v1.begin();
		iter = v1.erase(iter);

		int temp = *iter;

		v1.push_back(temp);
		v1.erase(iter);
	}

	int len = v2.size();

	for (int i = 0; i < len; i++)
		cout << v2[i] << ' ';

	cout << v1[0] << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> v;

	cin >> n;

	while (n >= 10) {
		v.push_back(n % 10);
		n /= 10;
	}

	v.push_back(n);

	int size = v.size();

	for (int i = size; i > 1; i--) {
		for (int j = 0; j < i - 1; j++) {
			int temp;

			if (v[j + 1] > v[j]) {
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << v[i];

	cout << endl;

	return 0;
}
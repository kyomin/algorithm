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

		v.push_back(n);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - (i + 1); j++) {
			if (v[j] > v[j + 1])
			{
				int temp = v[j + 1];
				v[j + 1] = v[j];
				v[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << v[i] << endl;

	return 0;
}
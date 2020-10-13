#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		string temp = "";
		vector<int> v;

		while (N != 1) {
			temp += (char)('0' + (N % 2));
			N /= 2;
		}

		temp += (char)('0' + N);

		for (int i = 0; i < temp.size(); i++)
			if (temp[i] == '1')
				v.push_back(i);

		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';

		cout << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	vector<double> v;

	while (true) {
		double num;
		cin >> num;

		if (num == 999)
			break;

		v.push_back(num);
	}

	for (int i = 1; i < v.size(); i++) {
		double prev = v[i - 1];
		double cur = v[i];

		cout << (cur - prev) << endl;
	}

	return 0;
}
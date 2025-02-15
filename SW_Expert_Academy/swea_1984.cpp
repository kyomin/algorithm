#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<double> v;
		v.resize(10);

		for (int i = 0; i < 10; i++)
			cin >> v[i];

		double max_num = *max_element(v.begin(), v.end());
		double min_num = *min_element(v.begin(), v.end());

		double sum = 0;
		for (int i = 0; i < 10; i++)
			sum += v[i];

		sum -= max_num;
		sum -= min_num;

		double mean = (sum / 8);
		mean = round(mean);

		cout << '#' << t << ' ' << mean << '\n';
	}

	return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case) {
		double sum = 0;

		for (int i = 0; i < 10; i++) {
			double n;
			cin >> n;

			sum += n;
		}
		
		cout << '#' << test_case << ' ' << (int)(round(sum/10)) << '\n';
	}

	return 0;
}
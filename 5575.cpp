#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; i++) {
		int start_h, start_m, start_s;
		int end_h, end_m, end_s;

		cin >> start_h >> start_m >> start_s;
		cin >> end_h >> end_m >> end_s;

		if (end_s < start_s) {
			end_s += 60;
			end_m -= 1;

			end_s -= start_s;
		} else {
			end_s -= start_s;
		}

		if (end_m < start_m) {
			end_m += 60;
			end_h -= 1;

			end_m -= start_m;
		} else {
			end_m -= start_m;
		}

		end_h -= start_h;

		cout << end_h << ' ' << end_m << ' ' << end_s << '\n';
	}

	return 0;
}
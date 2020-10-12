#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	unsigned long long n, m;
	cin >> n >> m;

	unsigned long long count5_of_mother = 0;
	unsigned long long count2_of_mother = 0;
	unsigned long long count5_of_son = 0;
	unsigned long long count2_of_son = 0;

	unsigned long long init2 = 2;
	unsigned long long init5 = 5;

	// count the number of 2 of mother
	while (init2 <= n) {
		count2_of_mother += n / init2;
		init2 *= 2;
	}

	// count the number of 5 of mother
	while (init5 <= n) {
		count5_of_mother += n / init5;
		init5 *= 5;
	}

	// initialize the variables again
	init2 = 2;
	init5 = 5;

	while (init2 <= m) {
		count2_of_son += m / init2;
		init2 *= 2;
	}

	while (init5 <= m) {
		count5_of_son += m / init5;
		init5 *= 5;
	}

	init2 = 2;
	init5 = 5;

	while (init2 <= (n - m)) {
		count2_of_son += (n - m) / init2;
		init2 *= 2;
	}

	while (init5 <= (n - m)) {
		count5_of_son += (n - m) / init5;
		init5 *= 5;
	}

	unsigned long long count2 = count2_of_mother - count2_of_son;
	unsigned long long count5 = count5_of_mother - count5_of_son;

	if (count5 > count2)
		cout << count2 << '\n';
	else
		cout << count5 << '\n';

	return 0;
}
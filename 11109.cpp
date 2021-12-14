#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int d, n, s, p;
		cin >> d >> n >> s >> p;

		int serial = (s*n);
		int parallel = d + (p*n);

		if (serial < parallel)
			cout << "do not parallelize" << endl;
		else if(serial > parallel)
			cout << "parallelize" << endl;
		else
			cout << "does not matter" << endl;
	}

	return 0;
}
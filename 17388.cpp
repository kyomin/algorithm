#include <iostream>
#include <string>

using namespace std;

int three_univ_partiality[3];
string three_univ[3] = {
	"Soongsil",
	"Korea",
	"Hanyang"
};

int main() {
	cin >> three_univ_partiality[0] >> three_univ_partiality[1] >> three_univ_partiality[2];

	int min = three_univ_partiality[0];
	int min_index = 0;
	int sum = min;

	for (int i = 1; i < 3; i++) {
		sum += three_univ_partiality[i];

		if (min > three_univ_partiality[i]) {
			min = three_univ_partiality[i];
			min_index = i;
		}
	}

	if (sum >= 100) {
		cout << "OK" << endl;
		return 0;
	}

	cout << three_univ[min_index] << endl;

	return 0;
}
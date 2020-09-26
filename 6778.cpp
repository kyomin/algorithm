#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int antenna, eyes;
	cin >> antenna >> eyes;

	// TroyMartian
	if (antenna >= 3 && eyes <= 4)
		cout << "TroyMartian" << '\n';

	// VladSaturnian
	if (antenna <= 6 && eyes >= 2)
		cout << "VladSaturnian" << '\n';

	// GraemeMercurian
	if (antenna <= 2 && eyes <= 3)
		cout << "GraemeMercurian" << '\n';

	return 0;
}
#include <iostream>

using namespace std;

int main() {
	int x, y;
	int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int total_day = 0;
	int day;

	cin >> x >> y;

	for (int i = 0; i < x; i++)
		total_day += arr[i];

	total_day += y;
	day = total_day % 7;

	switch (day) {
	case 0:
		cout << "SUN" << endl;
		break;

	case 1:
		cout << "MON" << endl;
		break;

	case 2:
		cout << "TUE" << endl;
		break;

	case 3:
		cout << "WED" << endl;
		break;

	case 4:
		cout << "THU" << endl;
		break;

	case 5:
		cout << "FRI" << endl;
		break;

	case 6:
		cout << "SAT" << endl;
		break;
	}

	return 0;
}
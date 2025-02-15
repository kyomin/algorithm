#include <iostream>

using namespace std;

int main() {
	while (true) {
		int boy_nums, girl_nums;
		cin >> boy_nums >> girl_nums;

		if (boy_nums == 0 && girl_nums == 0)
			break;

		cout << boy_nums + girl_nums << endl;
	}

	return 0;
}
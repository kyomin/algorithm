#include <iostream>

using namespace std;

int main() {
	int resultStick, curStick = 0, stick = 64, ans = 0;

	cin >> resultStick;

	while (true) {
		if (curStick + stick <= resultStick) {
			curStick += stick;
			ans++;
		}
		
		if (curStick == resultStick)
			break;

		stick /= 2;
	}

	cout << ans << '\n';

	return 0;
}
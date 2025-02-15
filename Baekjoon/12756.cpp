#include <iostream>
using namespace std;

int main() {
	int attackA, lifeA;
	cin >> attackA >> lifeA;

	int attackB, lifeB;
	cin >> attackB >> lifeB;

	while (true) {
		lifeA -= attackB;
		lifeB -= attackA;

		if (lifeA <= 0 || lifeB <= 0)
			break;
	}

	if (lifeA <= 0 && lifeB <= 0)
		cout << "DRAW" << endl;
	else if (lifeA <= 0)
		cout << "PLAYER B" << endl;
	else
		cout << "PLAYER A" << endl;

	return 0;
}
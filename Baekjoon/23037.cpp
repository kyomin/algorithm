#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string n;
	cin >> n;
	
	int sum = 0;
	int len = n.length();

	for (int i = 0; i < len; i++) {
		int disit = (int)(n[i] - '0');

		sum += pow(disit, 5);
	}

	cout << sum << endl;

	return 0;
}
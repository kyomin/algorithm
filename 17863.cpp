#include <iostream>
#include <string>

using namespace std;

int main() {
	string number;
	cin >> number;

	if (number.substr(0, 3) == "555")
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}
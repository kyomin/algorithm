#include <iostream>
#include <map>
using namespace std;

int main() {
	map<char, string> clubs;

	clubs['M'] = "MatKor";
	clubs['W'] = "WiCys";
	clubs['C'] = "CyKor";
	clubs['A'] = "AlKor";
	clubs['$'] = "$clear";

	char ch;
	cin >> ch;

	cout << clubs[ch] << endl;

	return 0;
}
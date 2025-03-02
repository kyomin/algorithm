#include <iostream>
using namespace std;

int main() {
	char alpha;
	cin >> alpha;

	if (alpha == 'N' || alpha == 'n')
		cout << "Naver D2" << endl;
	else
		cout << "Naver Whale" << endl;

	return 0;
}
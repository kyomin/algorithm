#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int case1 = N - ((N / 100) * 22);
	int case2 = N - ((((N / 100) * 20) / 100) * 22);

	cout << case1 << ' ' << case2 << endl;

	return 0;
}
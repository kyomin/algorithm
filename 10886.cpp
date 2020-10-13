#include <iostream>

using namespace std;

int main() {
	int vote[2];
	vote[0] = 0;
	vote[1] = 0;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		vote[n]++;
	}

	if (vote[0] > vote[1])
		cout << "Junhee is not cute!" << endl;
	else
		cout << "Junhee is cute!" << endl;

	return 0;
}
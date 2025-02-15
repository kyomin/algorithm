#include <iostream>

using namespace std;

int calcWineNums(int n, int K, int P) {
	return ((K*n) + (P*n*n));
}

int main() {
	int sum = 0;
	int C, K, P;
	cin >> C >> K >> P;

	for (int n = 1; n <= C; n++) 
		sum += calcWineNums(n, K, P);
	
	cout << sum << endl;

	return 0;
}
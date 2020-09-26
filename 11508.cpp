#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<int> products;
	int sum = 0;

	cin >> N;

	products.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> products[i];
		sum += products[i];
	}
	
	sort(products.begin(), products.end());

	for (int i = N - 3; i >= 0; i -= 3)
		sum -= products[i];

	cout << sum << '\n';

	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int s = 1;
	int e = 1;
	int sum = 0;
	int cnt = 0;
	while (true) {
		if (s > N && e > N)
			break;

		if (sum == N)
			cnt++;

		if (e > N || sum >= N) {
			sum -= s;
			s++;
		}
		else {
			sum += e;
			e++;
		}
	}

	cout << cnt << endl;

	return 0;
}
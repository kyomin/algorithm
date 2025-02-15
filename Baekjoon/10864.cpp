#include <iostream>

using namespace std;

int students[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;

		students[a]++;
		students[b]++;
	}

	for (int n = 1; n <= N; n++) 
		cout << students[n] << '\n';
	
	return 0;
}
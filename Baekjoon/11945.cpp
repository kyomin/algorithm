#include <iostream>
#include <string>

using namespace std;

string fish_bread[10];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> fish_bread[i];

	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--)
			cout << fish_bread[i][j];

		cout << '\n';
	}

	return 0;
}
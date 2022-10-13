#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	cout << "int a;" << '\n';
	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			cout << "int *ptr = &a;" << '\n';
			continue;
		}

		if (i == 2) {
			cout << "int **ptr2 = &ptr;" << '\n';
			continue;
		}

		string stars = "";
		for (int j = 0; j < i; j++)
			stars += "*";

		cout << "int " << stars << "ptr" << i << " = &ptr" << i - 1 << ';' << '\n';
	}

	return 0;
}
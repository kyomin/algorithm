#include <iostream>

using namespace std;

int a[50][2];

// Root -> L -> R
void preorder(int x) {
	if (x == -1)
		return;

	cout << (char)(x + 'A');

	preorder(a[x][0]);
	preorder(a[x][1]);
}

// L -> Root -> R
void inorder(int x) {
	if (x == -1)
		return;

	inorder(a[x][0]);
	cout << (char)(x + 'A');
	inorder(a[x][1]);
}

// L -> R -> Root
void postorder(int x) {
	if (x == -1)
		return;

	postorder(a[x][0]);
	postorder(a[x][1]);
	cout << (char)(x + 'A');
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		char x, y, z;
		cin >> x >> y >> z;

		x = x - 'A';

		if (y == '.')
			a[x][0] = -1;
		else
			a[x][0] = y - 'A';

		if (z == '.')
			a[x][1] = -1;
		else
			a[x][1] = z - 'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';

	return 0;
}
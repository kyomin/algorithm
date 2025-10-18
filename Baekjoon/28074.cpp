#include <iostream>
#include <string>
using namespace std;

/*
	0 -> M
	1 -> O
	2 -> B
	3 -> I
	4 -> S
*/
bool visited[5];

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'M') {
			visited[0] = true;
		}
		else if (str[i] == 'O') {
			visited[1] = true;
		}
		else if (str[i] == 'B') {
			visited[2] = true;
		}
		else if (str[i] == 'I') {
			visited[3] = true;
		}
		else if (str[i] == 'S') {
			visited[4] = true;
		}
	}

	bool flag = true;
	for (int i = 0; i < 5; i++) {
		if (!visited[i]) {
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
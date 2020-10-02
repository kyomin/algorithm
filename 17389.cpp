#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	
	cin >> N;
	cin >> str;

	int score = 0;
	int bonus = 0;

	for (int i = 0; i < N; i++) {
		if (str[i] == 'O') {
			score += (i + 1) + bonus;
			bonus++;
		}
		else {
			bonus = 0;
		}
	}
	
	cout << score << endl;

	return 0;
}
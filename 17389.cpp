#include <iostream>
#include <string>

using namespace std;

int main() {
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
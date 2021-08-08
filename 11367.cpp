#include <iostream>
#include <string>

using namespace std;

string getGrade(int score) {
	if (score >= 97 && score <= 100)
		return "A+";
	else if (score >= 90 && score <= 96)
		return "A";
	else if (score >= 87 && score <= 89)
		return "B+";
	else if (score >= 80 && score <= 86)
		return "B";
	else if (score >= 77 && score <= 79)
		return "C+";
	else if (score >= 70 && score <= 76)
		return "C";
	else if (score >= 67 && score <= 69)
		return "D+";
	else if (score >= 60 && score <= 66)
		return "D";
	else
		return "F";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string student;
		int score;
		cin >> student >> score;
		cout << student << ' ' << getGrade(score) << '\n';
	}

	return 0;
}
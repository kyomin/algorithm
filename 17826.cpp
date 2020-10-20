#include <iostream>
#include <string>

using namespace std;

int students[50];
int my_score;

// 학점 계산 함수
string calc_grade(int rank) {
	if (rank >= 1 && rank <= 5)
		return "A+";
	else if (rank >= 6 && rank <= 15)
		return "A0";
	else if (rank >= 16 && rank <= 30)
		return "B+";
	else if (rank >= 31 && rank <= 35)
		return "B0";
	else if (rank >= 36 && rank <= 45)
		return "C+";
	else if (rank >= 46 && rank <= 48)
		return "C0";
	else if (rank >= 49 && rank <= 50)
		return "F";
}

int main() {
	string result;

	for (int i = 0; i < 50; i++)
		cin >> students[i];

	cin >> my_score;

	for (int i = 0; i < 50; i++)
		if (my_score == students[i])
			result = calc_grade(i + 1);

	cout << result << '\n';

	return 0;
}
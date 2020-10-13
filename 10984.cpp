#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		double total_score = 0;
		int total_grade = 0;

		for (int i = 0; i < N; i++) {
			double score;
			int ratio;
			cin >> ratio >> score;

			total_grade += ratio;
			total_score += (ratio*score);
		}

		double GPA = total_score / total_grade;

		GPA = ceil(GPA * 10);
		GPA /= 10;

		printf("%d %.1f\n", total_grade, GPA);
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	while (true) {
		int N;
		cin >> N;

		if (N == 0)
			break;

		vector<pair<string, float>> students;
		float max = 0;
		for (int n = 0; n < N; n++) {
			string student;
			float height;
			cin >> student >> height;

			if (height > max)
				max = height;

			students.push_back(make_pair(student, height));
		}

		vector<string> highest_students;
		for (int i = 0; i < N; i++) {
			if (students[i].second == max)
				highest_students.push_back(students[i].first);
		}

		int len = highest_students.size();
		for (int i = 0; i < len - 1; i++)
			cout << highest_students[i] << ' ';
		cout << highest_students[len - 1] << endl;
	}

	return 0;
}
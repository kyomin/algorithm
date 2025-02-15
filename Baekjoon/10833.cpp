#include <iostream>

using namespace std;

int main() {
	int result = 0;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num_of_students, num_of_apples;
		cin >> num_of_students >> num_of_apples;
		result += (num_of_apples % num_of_students);
	}

	cout << result << '\n';

	return 0;
}
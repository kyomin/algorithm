#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int A, B, sum;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A >> B;
		sum = A + B;

		string str = "Case #" + to_string(i) + ": " + to_string(A) +
			" + " + to_string(B) + " = " + to_string(sum);

		cout << str << endl;
	}

	return 0;
}
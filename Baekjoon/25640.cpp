#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0;
	string mbti;
	int N;
	cin >> mbti >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		if (s == mbti)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}
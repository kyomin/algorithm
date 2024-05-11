#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isGoodWord(string word) {
	stack<char> st;

	for (char ch : word) {
		if (st.empty()) {
			st.push(ch);

			continue;
		}

		if (st.top() == ch) {
			st.pop();

			continue;
		}

		st.push(ch);
	}

	if (st.empty())
		return true;
	else
		return false;
}

int main() {
	int cnt = 0;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;

		if (isGoodWord(word))
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}
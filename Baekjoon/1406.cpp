#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N; // 입력할 명령어의 개수
	string str; // 초기에 입력되는 문자열

	// 입력하는 명령어들을 담는다.
	vector<string> v;

	vector<char> A;
	vector<char> B;

	cin >> str;
	cin.ignore();

	cin >> N;
	cin.ignore();

	// 스택 A에 입력받은 문자열의 문자들을 담는다.
	for (int i = 0; i < str.size(); i++) 
		A.push_back(str[i]);

	for (int i = 0; i < N; i++) {
		string temp;
		getline(cin, temp);

		v.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		if (v[i][0] == 'L') {
			if (A.size() != 0) {
				char c = A[A.size() - 1];
				A.pop_back();
				B.push_back(c);
			}
		}
		else if (v[i][0] == 'D') {
			if (B.size() != 0) {
				char c = B[B.size() - 1];
				B.pop_back();
				A.push_back(c);
			}
		}
		else if (v[i][0] == 'B') {
			if (A.size() != 0)
				A.pop_back();
		}
		else
			A.push_back(v[i][2]);
	}

	for (int i = 0; i < A.size(); i++)
		cout << A[i];

	for (int i = B.size() - 1; i >= 0; i--)
		cout << B[i];

	cout << '\n';

	return 0;
}
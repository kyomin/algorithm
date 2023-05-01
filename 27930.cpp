#include <iostream>
#include <string>
using namespace std;

int main() {
	string yonsei = "YONSEI";
	string korea = "KOREA";
	int yonseiIndex = 0;
	int koreaIndex = 0;
	
	string S;
	cin >> S;
	int len = S.length();
	for (int i = 0; i < len; i++) {
		if (S[i] == yonsei[yonseiIndex])
			yonseiIndex++;

		if (S[i] == korea[koreaIndex])
			koreaIndex++;

		if (yonseiIndex == yonsei.length()) {
			cout << "YONSEI" << endl;
			break;
		}

		if (koreaIndex == korea.length()) {
			cout << "KOREA" << endl;
			break;
		}
	}

	return 0;
}
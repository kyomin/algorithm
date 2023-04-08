#include <iostream>
#include <string>
using namespace std;

bool P[14];
bool K[14];
bool H[14];
bool T[14];

int main() {
	string S;
	cin >> S;

	int len = S.length();
	for (int i = 0; i < len; i += 3) {
		string card = S.substr(i, 3);
		char picture = card[0];
		int num = atoi(card.substr(1, 2).c_str());

		switch (picture) {
		case 'P': {
			if (P[num]) {
				cout << "GRESKA" << endl;
				return 0;
			}
			else {
				P[num] = true;
			}

			break;
		}
		case 'K': {
			if (K[num]) {
				cout << "GRESKA" << endl;
				return 0;
			}
			else {
				K[num] = true;
			}

			break;
		}
		case 'H': {
			if (H[num]) {
				cout << "GRESKA" << endl;
				return 0;
			}
			else {
				H[num] = true;
			}

			break;
		}
		case 'T': {
			if (T[num]) {
				cout << "GRESKA" << endl;
				return 0;
			}
			else {
				T[num] = true;
			}

			break;
		}
		}
	}

	int cntP = 13;
	int cntK = 13;
	int cntH = 13;
	int cntT = 13;
	
	for (int i = 1; i <= 13; i++)
		if (P[i])
			cntP -= 1;

	for (int i = 1; i <= 13; i++)
		if (K[i])
			cntK -= 1;

	for (int i = 1; i <= 13; i++)
		if (H[i])
			cntH -= 1;

	for (int i = 1; i <= 13; i++)
		if (T[i])
			cntT -= 1;

	cout << cntP << ' ' << cntK << ' ' << cntH << ' ' << cntT << endl;

	return 0;
}
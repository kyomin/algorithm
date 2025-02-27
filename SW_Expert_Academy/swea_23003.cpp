#include <iostream>
#include <string>
using namespace std;

bool isRed(string color) {
	if (color == "red")
		return true;
	else
		return false;
}

bool isOrange(string color) {
	if (color == "orange")
		return true;
	else
		return false;
}

bool isYellow(string color) {
	if (color == "yellow")
		return true;
	else
		return false;
}

bool isGreen(string color) {
	if (color == "green")
		return true;
	else
		return false;
}

bool isBlue(string color) {
	if (color == "blue")
		return true;
	else
		return false;
}

bool isPurple(string color) {
	if (color == "purple")
		return true;
	else
		return false;
}

// 서로 같은 색인가?
bool isCaseE(string color1, string color2) {
	return color1 == color2;
}

// 색상환에서 인접한(한 변을 공유하고 있는) 색인가?
bool isCaseA(string color1, string color2) {
	if ((isRed(color1) && isOrange(color2)) || (isOrange(color1) && isRed(color2)))
		return true;
	else if ((isOrange(color1) && isYellow(color2)) || (isYellow(color1) && isOrange(color2)))
		return true;
	else if ((isYellow(color1) && isGreen(color2)) || (isGreen(color1) && isYellow(color2)))
		return true;
	else if ((isGreen(color1) && isBlue(color2)) || (isBlue(color1) && isGreen(color2)))
		return true;
	else if ((isBlue(color1) && isPurple(color2)) || (isPurple(color1) && isBlue(color2)))
		return true;
	else if ((isPurple(color1) && isRed(color2)) || (isRed(color1) && isPurple(color2)))
		return true;
	else
		return false;
}

// 색상환에서 서로 반대에 있는(마주보고 있는) 색인가?
bool isCaseC(string color1, string color2) {
	if ((isRed(color1) && isGreen(color2)) || (isGreen(color1) && isRed(color2)))
		return true;
	else if ((isOrange(color1) && isBlue(color2)) || (isBlue(color1) && isOrange(color2)))
		return true;
	else if ((isYellow(color1) && isPurple(color2)) || (isPurple(color1) && isYellow(color2)))
		return true;
	else
		return false;
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string color1, color2;
		cin >> color1 >> color2;

		if (isCaseE(color1, color2))
			cout << 'E' << endl;
		else if(isCaseA(color1, color2))
			cout << 'A' << endl;
		else if(isCaseC(color1, color2))
			cout << 'C' << endl;
		else
			cout << 'X' << endl;
	}

	return 0;
}
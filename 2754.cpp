#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(1);

	map<string, float> grades;
	string grade;

	grades["A+"] = 4.3;
	grades["A0"] = 4.0;
	grades["A-"] = 3.7;
	grades["B+"] = 3.3;
	grades["B0"] = 3.0;
	grades["B-"] = 2.7;
	grades["C+"] = 2.3;
	grades["C0"] = 2.0;
	grades["C-"] = 1.7;
	grades["D+"] = 1.3;
	grades["D0"] = 1.0;
	grades["D-"] = 0.7;
	grades["F"] = 0.0;

	cin >> grade;

	cout << grades.find(grade)->second << endl;

	return 0;
}
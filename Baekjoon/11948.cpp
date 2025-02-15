#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> science;
	vector<int> society;

	science.resize(4);
	society.resize(2);

	for (int i = 0; i < 4; i++)
		cin >> science[i];

	for (int i = 0; i < 2; i++)
		cin >> society[i];

	sort(science.begin(), science.end());
	sort(society.begin(), society.end());

	int sum = 0;
	for (int i = 3; i >= 1; i--)
		sum += science[i];

	sum += society[1];

	cout << sum << endl;

	return 0;
}
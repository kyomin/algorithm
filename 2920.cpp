#include <iostream>

using namespace std;

int main() {
	int judge = 0;
	int arr[8];

	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	for (int i = 0; i < 7; i++)
		if (arr[i] + 1 == arr[i + 1])
			judge++;

		else if (arr[i] - 1 == arr[i + 1])
			judge--;

	if (judge == 7)
		cout << "ascending" << endl;
	else if (judge == -7)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;

	return 0;
}
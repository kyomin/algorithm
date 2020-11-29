#include <iostream>
#include <string>

using namespace std;

int main() {
	int V;
	string votes;
	cin >> V;
	cin >> votes;

	int num_A = 0;
	int num_B = 0;

	for (int i = 0; i < V; i++) {
		if (votes[i] == 'A')
			num_A++;
		else
			num_B++;
	}

	if (num_A > num_B)
		cout << 'A' << '\n';
	else if(num_A < num_B)
		cout << 'B' << '\n';
	else
		cout << "Tie" << '\n';

	return 0;
}
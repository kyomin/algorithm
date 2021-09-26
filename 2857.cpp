#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> agents;

	for (int i = 1; i <= 5; i++) {
		string str;
		cin >> str;

		bool flag = false;
		int len = str.length();
		for (int start = 0; start <= len - 3; start++) {
			if (str.substr(start, 3) == "FBI") {
				flag = true;
				break;
			}
		}

		if (flag)
			agents.push_back(i);
	}

	if (agents.size() != 0) {
		for (int i = 0; i < agents.size() - 1; i++)
			cout << agents[i] << ' ';

		cout << agents[agents.size() - 1] << endl;
	}
	else {
		cout << "HE GOT AWAY!" << endl;
	}

	return 0;
}
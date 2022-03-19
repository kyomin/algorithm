#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<string> players;
	map<string, int> complete_players;

	cin >> N;
	players.resize(N);

	for (int i = 0; i < N; i++)
		cin >> players[i];

	for (int i = 0; i < (N - 1); i++) {
		string player;
		cin >> player;

		if (complete_players.find(player) == complete_players.end()) {
			complete_players[player] = 1;
		}
		else {
			complete_players.find(player)->second += 1;
		}
	}

	for (int i = 0; i < N; i++) {
		string player = players[i];

		if (complete_players.find(player) == complete_players.end()) {
			cout << player << endl;
			break;
		}
		else if (complete_players.find(player)->second == 0) {
			cout << player << endl;
			break;
		}
		else {
			complete_players.find(player)->second -= 1;
		}
	}

	return 0;
}
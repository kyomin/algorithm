#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// first: player, second: score
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second > p2.second) {
		return true;
	}
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<vector<int>> players;
	vector<pair<int, int>> player_and_scores;
	int N, M;
	cin >> N >> M;

	players.resize(N);
	
	for (int n = 0; n < N; n++) {
		players[n].resize(M);
		player_and_scores.push_back(make_pair(n + 1, 0));
	}

	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			cin >> players[n][m];

	for (int n = 0; n < N; n++)
		sort(players[n].begin(), players[n].end());

	for (int m = 0; m < M; m++) {
		int max = 0;

		for (int n = 0; n < N; n++)
			if (players[n][m] > max)
				max = players[n][m];
		
		for (int n = 0; n < N; n++)
			if (players[n][m] == max)
				player_and_scores[n].second += 1;
	}

	sort(player_and_scores.begin(), player_and_scores.end(), comp);

	int max_score = player_and_scores[0].second;
	vector<int> best_playes;

	for (int n = 0; n < N; n++) {
		if (player_and_scores[n].second == max_score)
			best_playes.push_back(player_and_scores[n].first);
		else
			break;
	}

	int len = best_playes.size();

	for (int i = 0; i < len - 1; i++)
		cout << best_playes[i] << ' ';

	cout << best_playes[len - 1] << '\n';

	return 0;
}
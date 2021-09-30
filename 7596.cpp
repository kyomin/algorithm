#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int test_case = 1;

	while (true) {
		vector<string> songs;
		int N;
		cin >> N;
		cin.get();

		if (N == 0)
			break;

		for (int n = 0; n < N; n++) {
			string song;
			getline(cin, song);
			
			songs.push_back(song);
		}

		sort(songs.begin(), songs.end());

		cout << test_case << endl;
		for (int n = 0; n < N; n++) 
			cout << songs[n] << endl;

		test_case++;
	}

	return 0;
}
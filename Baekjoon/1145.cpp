#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

int arr[5];
vector<int> vc;
int ans = numeric_limits<int>::max();

void GCM() {
	int biggest = vc[2];

	while (true) {
		if (biggest%vc[0] == 0 && biggest%vc[1] == 0 && biggest%vc[2] == 0) {
			ans = min(ans, biggest);
			break;
		}

		biggest++;
	}
}

void DFS(int cnt) {
	if (vc.size() == 3) {
		sort(vc.begin(), vc.end());
		GCM();

		return;
	}

	for (int i = cnt; i < 5; i++) {
		if (vc.size() < 3) {
			vc.push_back(arr[i]);
			DFS(i + 1);
			vc.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	sort(arr, arr + 5);

	DFS(0);

	cout << ans << '\n';

	return 0;
}
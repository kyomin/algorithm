#include <iostream>
#include <vector>

using namespace std;

// 1000 이하의 모든 삼각수를 담는다.
vector<int> all_triangle;

// 모든 케이스에 대한 3개의 삼각수를 담는다.
vector<int> vc;

// 3개가 되었을 때, 입력 수와 일치하는지 판단한다.
bool judge;

void dfs(int N) {
	if (vc.size() == 3) {
		int hap = 0;

		for (auto i : vc)
			hap += i;

		if (hap == N)
			judge = true;

		return;
	}

	for (int i = 0; i < all_triangle.size(); i++) {
		if (!judge) {
			vc.push_back(all_triangle[i]);
			dfs(N);
			vc.pop_back();
		}
		else
			break;
	}
}

int main() {
	int T;
	int i = 1;

	while (true) {
		if ((i*(i + 1)) / 2 >= 1000) {
			all_triangle.push_back((i*(i + 1)) / 2);
			break;
		}

		all_triangle.push_back((i*(i + 1)) / 2);

		i++;
	}

	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		judge = false;

		dfs(N);

		if (judge)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}

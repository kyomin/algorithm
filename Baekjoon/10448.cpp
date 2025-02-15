#include <iostream>
#include <vector>

using namespace std;

// 1000 ������ ��� �ﰢ���� ��´�.
vector<int> all_triangle;

// ��� ���̽��� ���� 3���� �ﰢ���� ��´�.
vector<int> vc;

// 3���� �Ǿ��� ��, �Է� ���� ��ġ�ϴ��� �Ǵ��Ѵ�.
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

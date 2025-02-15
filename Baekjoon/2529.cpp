#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector<string> answers;
vector<char> signs;
vector<int> vc;
bool visit[10];

void dfs() {
	if (vc.size() == M) {
		bool flag = true;
		for (int i = 0; i < N; i++) {
			char sign = signs[i];

			if (sign == '<') {
				if (vc[i] > vc[i + 1]) {
					flag = false;
					break;
				}
				else {
					continue;
				}
			}
			else {
				if (vc[i] < vc[i + 1]) {
					flag = false;
					break;
				}
				else {
					continue;
				}
			}
		}

		if (flag) {
			string str = "";
			for (auto num : vc)
				str += to_string(num);

			answers.push_back(str);
		}

		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!visit[i]) {
			visit[i] = true;
			vc.push_back(i);

			dfs();

			vc.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N;
	M = N + 1;
	signs.resize(N);
	for (int i = 0; i < N; i++)
		cin >> signs[i];

	dfs();

	int last = answers.size() - 1;
	cout << answers[last] << endl;
	cout << answers[0] << endl;

	return 0;
}
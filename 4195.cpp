#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int friends[200001];						// 친구들의 부모 노드를 담는다.

void init() {
	for (int i = 1; i <= 200000; i++)
		friends[i] = i;
}

int Find(int x) {
	// root인 경우 x를 반환
	if (x == friends[x]) {
		return x;
	}
	else {
		int p = Find(friends[x]);
		friends[x] = p;

		return p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y)
		friends[y] = x;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int F;
		cin >> F;

		init();
		int cur_node = 1;

		// 친구 문자열을 숫자 노드에 매핑
		unordered_map<string, int> friend_node;		

		for (int f = 0; f < F; f++) {
			string f1, f2;
			int n1, n2;
			cin >> f1 >> f2;

			// f1이 처음 등장한 친구라면
			if (friend_node.find(f1) == friend_node.end()) {
				friend_node[f1] = cur_node;
				n1 = cur_node;
				cur_node++;
			}
			else {
				n1 = friend_node[f1];
			}

			// f2이 처음 등장한 친구라면
			if (friend_node.find(f2) == friend_node.end()) {
				friend_node[f2] = cur_node;
				n2 = cur_node;
				cur_node++;
			}
			else {
				n2 = friend_node[f2];
			}
				
			Union(n1, n2);

			// 현재 속해있는 집합
			int cur_set = Find(n1);
			
			int friends_num = friend_node.size();
			int cnt = 0;

			for (int num = 1; num <= friends_num; num++) {
				if (Find(num) == cur_set)
					cnt++;
			}

			cout << cnt << '\n';
		}
	}

	return 0;
}
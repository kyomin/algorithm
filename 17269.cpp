#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// 알파벳 마다의 획의 횟수 저장!
	int A[26] = {
		3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2,
		1, 2, 1, 1, 1, 2, 2, 1
	};

	vector<int> v;
	int N, M;
	cin >> N >> M;

	string str1, str2;
	cin >> str1 >> str2;

	// 번갈아 이름을 붙여서 저장하기 위한 변수
	string result = "";

	// 만일 두 번째 이름이 길다면
	if (N < M) {
		// 일단 짧은 쪽까지 돌린 후에
		for (int i = 0; i < N; i++) {
			result += str1[i];
			result += str2[i];
		}

		// 나머지 긴 부분을 붙이기!
		for (int i = N; i < M; i++)
			result += str2[i];
	}
	// 위와 반대의 작업!
	else {
		for (int i = 0; i < M; i++) {
			result += str1[i];
			result += str2[i];
		}

		for (int i = M; i < N; i++)
			result += str1[i];
	}

	// 최종적으로 번갈아 붙인 이름의 길이 저장
	int len = result.size();

	// 벡터에다가 최종적으로 저장한 문자열의 각 알파벳의 가중치 저장!
	for (int i = 0; i < len; i++) {
		int n = (int)(result[i] - 65);
		v.push_back(A[n]);
	}

	// 최종적으로 더해나가는 연산에서는 마지막에 2개만 남으므로 길이가 2가 아닐 때까지!
	while (len != 2) {
		// 더하는 작업을 해준다.
		for (int i = 0; i < len - 1; i++) {
			v[i] += v[i + 1];

			if (v[i] >= 10)
				v[i] %= 10;
		}

		// 처음 길이를 담은 변수 감소시키기!
		len--;
	}

	// 최종적으로 v[0]과 v[1]에 담긴다. 이때, 10보다 크거나 같으면!
	if (v[0] >= 10)
		v[0] %= 10;

	if (v[0] != 0)
		cout << v[0] << v[1] << '%' << '\n';
	else
		cout << v[1] << '%' << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS�� ��� ��츦 Ž���ϸ� �ð� �ʰ�
// DP�� Ǭ��.
// ������ �����ߴ� ������ ������ + ���� ���ο� ���� Ȯ���ϴ� ���
// bool�� �迭�� �̿��Ͽ� ���� ���� ���� Ȯ��
int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<int> scores;
		int N;
		cin >> N;
		
		scores.resize(N);
		for (int i = 0; i < N; i++)
			cin >> scores[i];

		// ����� ���Ǹ� ���� ���� ������ ����
		sort(scores.begin(), scores.end());

		// N�� �ִ� ũ�Ⱑ 100, �ִ� ������ 100�̹Ƿ� ������ �ִ� ������ 10000
		bool possibleScores[10001] = { false, };

		// 0�� �׻� ������ �����̹Ƿ�
		possibleScores[0] = true;

		int max = 0;
		for (int i = 0; i < N; i++) {
			max += scores[i];

			// max���� �����Ѵ�. ������ 3�� ��� 0���� 0+3=3�� üũ�Ǹ�, 3���� 3+3=6�� ������ ������ üũ�Ѵ�.
			for (int k = max; k >= 0; k--)
				if (possibleScores[k])
					possibleScores[k + scores[i]] = true;
		}

		int cnt = 0;
		for (int i = 0; i <= max; i++)
			if (possibleScores[i])
				cnt++;

		cout << '#' << t << ' ' << cnt << '\n';
	}

	return 0;
}
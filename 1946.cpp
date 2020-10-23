#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		vector<pair<int, int>> candidates;
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int resume, interview;
			cin >> resume >> interview;

			candidates.push_back(make_pair(resume, interview));
		}
		
		// 일단 서류 등수를 기준으로 오름차순 정렬
		sort(candidates.begin(), candidates.end());

		int ans = 1;
		int cur_interview_rank = candidates[0].second;	// 현재 인터뷰 등수 기준

		for (int i = 1; i < candidates.size(); i++) {
			int interview_rank = candidates[i].second;

			if (cur_interview_rank > interview_rank) {
				cur_interview_rank = interview_rank;
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
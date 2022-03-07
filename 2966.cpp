#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	char arr1[3] = { 'A', 'B', 'C' };
	char arr2[4] = { 'B', 'A', 'B', 'C' };
	char arr3[6] = { 'C', 'C', 'A', 'A', 'B', 'B' };

	int N;
	string answer;
	cin >> N;
	cin >> answer;

	// 상근이 정답 계산
	int cnt1 = 0;
	for (int i = 0; i < N; i++) {
		int index = i % 3;
		char ans = arr1[index];

		if (answer[i] == ans)
			cnt1++;
	}

	// 창영이 정답 계산
	int cnt2 = 0;
	for (int i = 0; i < N; i++) {
		int index = i % 4;
		char ans = arr2[index];

		if (answer[i] == ans)
			cnt2++;
	}

	// 현진이 정답 계산
	int cnt3 = 0;
	for (int i = 0; i < N; i++) {
		int index = i % 6;
		char ans = arr3[index];

		if (answer[i] == ans)
			cnt3++;
	}

	vector<int> nums;
	nums.push_back(cnt1);
	nums.push_back(cnt2);
	nums.push_back(cnt3);

	sort(nums.begin(), nums.end());

	int max = nums[nums.size() - 1];

	cout << max << endl;

	if (cnt1 == max)
		cout << "Adrian" << endl;
	
	if (cnt2 == max)
		cout << "Bruno" << endl;

	if (cnt3 == max)
		cout << "Goran" << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int N) {
	string binary = "";

	while (N != 1) {
		int r = N % 2;
		
		binary += to_string(r);

		N /= 2;
	}

	binary += to_string(N);

	reverse(binary.begin(), binary.end());

	vector<int> binary_gaps;
	int len = binary.size();
	int cnt = 0;
	
	for (int i = 0; i < len; i++) {
		if (binary[i] == '0') {
			cnt += 1;
			continue;
		}

		binary_gaps.push_back(cnt);
		cnt = 0;
	}

	if (binary_gaps.size() == 0)
		return 0;
	else
		return *max_element(binary_gaps.begin(), binary_gaps.end());
}
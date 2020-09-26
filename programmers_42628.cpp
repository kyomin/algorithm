#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	vector<int> doubleHeap;		// 벡터로 이중 힙 구현

	int len = operations.size();

	for (int i = 0; i < len; i++) {
		vector<string> query = split(operations[i], ' ');

		// 삽입 작업이라면
		if (query[0] == "I") {
			doubleHeap.push_back(atoi(query[1].c_str()));

			sort(doubleHeap.begin(), doubleHeap.end());
		}
		else {	// 삭제 작업이라면
			if (query[1] == "1") {		// 최댓값 삭제!
				doubleHeap.pop_back();
			}
			else {		// 최솟값 삭제!
				vector<int>::iterator iter = doubleHeap.begin();
				doubleHeap.erase(iter);
			}
		}
	}

	len = doubleHeap.size();

	if (len == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(doubleHeap[len - 1]);
		answer.push_back(doubleHeap[0]);
	}

	return answer;
}

int main() {
	// test 1
	vector<int> result = solution({ "I 16", "D 1" });

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	cout << endl;


	// test 2
	result = solution({ "I 7", "I 5", "I -5", "D -1" });

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}

	cout << endl;

	return 0;
}
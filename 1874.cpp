#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	vector<int> stack1;
	vector<int> stack2;
	vector<char> result;
	int length = 0;
	bool judge = false;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		arr.push_back(n);
	}

	for (int i = 1; i < arr[0] + 1; i++) {
		stack1.push_back(i);
		result.push_back('+');
		length += 1;
	}

	result.push_back('-');
	stack2.push_back(stack1[stack1.size() - 1]);
	stack1.pop_back();

	int i = 1;

	while (true) {
		if (stack1.size() > 0) {
			if (arr[i] == stack1[stack1.size() - 1]) {
				stack2.push_back(stack1[stack1.size() - 1]);
				stack1.pop_back();
				result.push_back('-');
			}

			else if ((arr[i] != stack1[stack1.size() - 1]) && (arr[i] > stack1[stack1.size() - 1])) {

				while (length < arr[i]) {
					length += 1;
					stack1.push_back(length);
					result.push_back('+');
				}

				result.push_back('-');
				stack2.push_back(stack1[stack1.size() - 1]);
				stack1.pop_back();
			}

			else if ((arr[i] != stack1[stack1.size() - 1]) && (arr[i] < stack1[stack1.size() - 1]))
				break;
		}
		else if (stack2 == arr) {
			judge = true;
			break;
		}
		else if (stack1.size() == 0) {
			while (length < arr[i]) {
				length += 1;
				stack1.push_back(length);
				result.push_back('+');
			}

			result.push_back('-');
			stack2.push_back(stack1[stack1.size() - 1]);
			stack1.pop_back();
		}

		i += 1;
	}

	if (judge == true)
		for (int d = 0; d < result.size(); d++)
			cout << result[d] << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}
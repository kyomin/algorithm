#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solution(string str) {
	stack<char> parentheses;
	stack<int> num;

	int len = str.size();
	bool isClosed = false;	// ���� �ݴ� ��ȣ�� �����ΰ�?
	bool rightParentheses = true;
	int ans = 0;

	for (int i = 0; i < len; i++) {
		char c = str[i];

		// ���� ��ȣ��� �׳� �־��ֱ�
		if (c == '(' || c == '[') {
			parentheses.push(c);
			isClosed = false;
			continue;
		}

		if (c == ']') {
			// ¦�� ����� �Ǵµ� ũ�Ⱑ 0�̶��
			if (parentheses.size() == 0) {
				rightParentheses = false;
				break;
			}

			// ¦�� �� �´´ٸ�
			if (parentheses.top() != '[') {
				rightParentheses = false;
				break;
			}

			// �������� �ݴ� ��ȣ�� ���� ���� �ƴ϶��
			if (!isClosed) {
				parentheses.pop();

				if (parentheses.size() != 0) {
					num.push(3);
					isClosed = true;
				}
				else {
					int sum = 0;

					if (num.size() == 0) {
						ans += 3;
					}
					else {
						while (num.size() != 0) {
							sum += num.top();
							num.pop();
						}

						ans += (3 * sum);
					}
				}
			}
			else {  // �������� �ݴ� ��ȣ�� ���� ���̶��
				parentheses.pop();

				if (parentheses.size() != 0) {
					int n = num.top();
					num.pop();
					num.push(n * 3);
				}
				else {
					int sum = 0;

					if (num.size() == 0) {
						ans += 3;
					}
					else {
						while (num.size() != 0) {
							sum += num.top();
							num.pop();
						}

						ans += (3 * sum);
					}
				}
			}

			continue;
		}

		if (c == ')') {
			// ¦�� ����� �Ǵµ� ũ�Ⱑ 0�̶��
			if (parentheses.size() == 0) {
				rightParentheses = false;
				break;
			}

			// ¦�� �� �´´ٸ�
			if (parentheses.top() != '(') {
				rightParentheses = false;
				break;
			}

			// �������� �ݴ� ��ȣ�� ���� ���� �ƴ϶��
			if (!isClosed) {
				parentheses.pop();

				if (parentheses.size() != 0) {
					num.push(2);
					isClosed = true;
				}
				else {
					int sum = 0;

					if (num.size() == 0) {
						ans += 2;
					}
					else {
						while (num.size() != 0) {
							sum += num.top();
							num.pop();
						}

						ans += (2 * sum);
					}
				}
			}
			else {  // �������� �ݴ� ��ȣ�� ���� ���̶��
				parentheses.pop();

				if (parentheses.size() != 0) {
					int n = num.top();
					num.pop();
					num.push(n * 2);
				}
				else {
					int sum = 0;

					if (num.size() == 0) {
						ans += 2;
					}
					else {
						while (num.size() != 0) {
							sum += num.top();
							num.pop();
						}

						ans += (2 * sum);
					}
				}
			}

			continue;
		}
	}

	// �� ���ȴµ��� ���� ���ÿ� ���� �ִٸ�
	if (parentheses.size() != 0)
		return 0;

	if (!rightParentheses)
		return 0;
	else
		return ans;
}

int main() {
	string str;
	cin >> str;

	cout << solution(str) << endl;
	
	return 0;
}
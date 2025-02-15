#include <iostream>
#include <string>

using namespace std;

int n;
bool stop = false;

bool isSatisfy(string s) {
	int len = s.size();
	int loop = len / 2;		// ���� �� �ִ� Ƚ���� ������ ������ �����̴�.

	// ���� 1 ~ (len/2)���� �κ� ���ڿ� �񱳸� ���� �� ������
	for (int num = 1; num <= loop; num++) {
		for (int i = 0; i < len; i++) {
			if (i + num >= len)
				break;

			if (i + num + num - 1 >= len)
				break;

			string left = s.substr(i, num);
			string right = s.substr(i + num, num);

			// ���� ���� �߰ߵǴ� ����, ���� ������ ���� ���ϴ� ���̴�.
			if (left == right)
				return false;
		}
	}

	// ���� for���� ����ߴٸ�, ���� �����̴�.
	return true;
}

void dfs(int len, string s) {
	if (stop)
		return;

	if (n == len) {
		stop = true;
		cout << s << '\n';
	}
	else {
		for(int i=1; i<=3; i++)
			if(isSatisfy(s + to_string(i)))
				dfs(len+1, s + to_string(i));
	}
}

int main() {
	cin >> n;

	dfs(1, "1");

	return 0;
}
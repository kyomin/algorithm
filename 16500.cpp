#include <iostream>
#include <vector>
#include <string>

using namespace std;

// result : ������� �ϴ� ���ڿ�, temp : �������� ������ ��� ���� ���ڿ�
string result, temp="";
vector<string> A;
int N, answer=0;

// str : ���Ӱ� ���ϰ��� �ϴ� ���ڿ�
bool promising(string str) {
	int len_of_temp = temp.size();
	int len_of_result = result.size();
	int len_of_str = str.size();

	// ���̸� �ʰ��ϴ� ��� �������� �ʴ�.
	if (len_of_temp + len_of_str > len_of_result) {
		return false;
	}

	// ���Ϸ��� ���ڿ��� ù ���ڰ� ��ġ�ϴ��� �˻��Ѵ�.
	if (result[len_of_temp] != str[0]) {
		return false;
	}

	// ���� 2���� ��츦 ����Ѵٸ� �����ϴ�.
	return true;
}

void dfs() {
	// �ش��� �߰��� ����
	if (temp == result) {
		answer = 1;
		return;
	}

	// �ߺ� �ܾ ����ϹǷ� �ߺ� üũ ���� �ʴ´�.
	for (int i = 0; i < N; i++) {
		if (promising(A[i])) {
			temp += A[i];
			dfs();

			if (answer == 1) {
				return;
			}

			// temp�� ������ ���ڿ��� ���ϱ� �� ���·� �ǵ�����
			int prevLen = temp.size() - A[i].size();
			temp = temp.substr(0, prevLen);
		}
	}

	// for���� ���� ���� �ܾ ���ٸ� ���̴�.
	return;
}

int main() {
	cin >> result;
	cin >> N;

	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	dfs();

	cout << answer << '\n';

	return 0;
}
#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C;
	int hours, minutes, seconds;

	cin >> A >> B >> C;

	cin >> seconds;

	/*  �־��� �ʸ� ������ ��, ��, �ʿ� ���� �����ֱ�  */
	minutes = seconds / 60;
	seconds %= 60;

	hours = minutes / 60;
	minutes %= 60;

	hours %= 24;

	A += hours;
	B += minutes;
	C += seconds;

	/*  �� ����� ������ �ø��� ó�����ֱ�  */
	B += (C / 60);
	C %= 60;

	A += (B / 60);
	B %= 60;

	A %= 24;

	cout << A << ' ' << B << ' ' << C << '\n';

	return 0;
}
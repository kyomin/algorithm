#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int val = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (val > 0)
        cout << 1 << '\n';   // �ݽð� ����
    else if (val < 0)
        cout << -1 << '\n';  // �ð� ����
    else
        cout << 0 << '\n';   // �������� ����

    return 0;
}
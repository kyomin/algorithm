#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int val = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (val > 0)
        cout << 1 << '\n';   // 반시계 방향
    else if (val < 0)
        cout << -1 << '\n';  // 시계 방향
    else
        cout << 0 << '\n';   // 일직선상에 있음

    return 0;
}
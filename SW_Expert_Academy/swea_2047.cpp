#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    for (char& ch : str) {
        if (islower(ch)) {
            ch = toupper(ch);
        }
    }

    cout << str << endl;

    return 0;
}
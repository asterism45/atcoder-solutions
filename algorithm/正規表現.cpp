#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    string S;
    cin >> S;

    cout << (regex_match(S, regex("(dream|dreamer|erase|eraser)*")) ? "YES" : "NO") << endl;
}
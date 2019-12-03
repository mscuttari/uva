#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n-- != 0) {
        string s;
        cin >> s;

        const char* str = s.c_str();
        int len = strlen(str);

        if (len <= 2) {
            // Positive result
            cout << "+" << endl;

        } else if (str[len - 2] == '3' && str[len - 1] == '5') {
            // Negative result
            cout << "-" << endl;

        } else if (str[0] == '9' && str[len - 1] == '4') {
            // Experiment failed
            cout << "*" << endl;

        } else {
            // Experiment not completed
            cout << "?" << endl;
        }
    }

    return 0;
}
